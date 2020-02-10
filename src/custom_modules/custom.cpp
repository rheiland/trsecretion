/*
###############################################################################
# If you use PhysiCell in your project, please cite PhysiCell and the version #
# number, such as below:                                                      #
#                                                                             #
# We implemented and solved the model using PhysiCell (Version x.y.z) [1].    #
#                                                                             #
# [1] A Ghaffarizadeh, R Heiland, SH Friedman, SM Mumenthaler, and P Macklin, #
#     PhysiCell: an Open Source Physics-Based Cell Simulator for Multicellu-  #
#     lar Systems, PLoS Comput. Biol. 14(2): e1005991, 2018                   #
#     DOI: 10.1371/journal.pcbi.1005991                                       #
#                                                                             #
# See VERSION.txt or call get_PhysiCell_version() to get the current version  #
#     x.y.z. Call display_citations() to get detailed information on all cite-#
#     able software used in your PhysiCell application.                       #
#                                                                             #
# Because PhysiCell extensively uses BioFVM, we suggest you also cite BioFVM  #
#     as below:                                                               #
#                                                                             #
# We implemented and solved the model using PhysiCell (Version x.y.z) [1],    #
# with BioFVM [2] to solve the transport equations.                           #
#                                                                             #
# [1] A Ghaffarizadeh, R Heiland, SH Friedman, SM Mumenthaler, and P Macklin, #
#     PhysiCell: an Open Source Physics-Based Cell Simulator for Multicellu-  #
#     lar Systems, PLoS Comput. Biol. 14(2): e1005991, 2018                   #
#     DOI: 10.1371/journal.pcbi.1005991                                       #
#                                                                             #
# [2] A Ghaffarizadeh, SH Friedman, and P Macklin, BioFVM: an efficient para- #
#     llelized diffusive transport solver for 3-D biological simulations,     #
#     Bioinformatics 32(8): 1256-8, 2016. DOI: 10.1093/bioinformatics/btv730  #
#                                                                             #
###############################################################################
#                                                                             #
# BSD 3-Clause License (see https://opensource.org/licenses/BSD-3-Clause)     #
#                                                                             #
# Copyright (c) 2015-2018, Paul Macklin and the PhysiCell Project             #
# All rights reserved.                                                        #
#                                                                             #
# Redistribution and use in source and binary forms, with or without          #
# modification, are permitted provided that the following conditions are met: #
#                                                                             #
# 1. Redistributions of source code must retain the above copyright notice,   #
# this list of conditions and the following disclaimer.                       #
#                                                                             #
# 2. Redistributions in binary form must reproduce the above copyright        #
# notice, this list of conditions and the following disclaimer in the         #
# documentation and/or other materials provided with the distribution.        #
#                                                                             #
# 3. Neither the name of the copyright holder nor the names of its            #
# contributors may be used to endorse or promote products derived from this   #
# software without specific prior written permission.                         #
#                                                                             #
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" #
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   #
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  #
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   #
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         #
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF        #
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    #
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN     #
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)     #
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  #
# POSSIBILITY OF SUCH DAMAGE.                                                 #
#                                                                             #
###############################################################################
*/

#include "./custom.h"

// declare cell definitions here 

Cell_Definition secretion_cell; 

void create_cell_types( void )
{
	// use the same random seed so that future experiments have the 
	// same initial histogram of oncoprotein, even if threading means 
	// that future division and other events are still not identical 
	// for all runs 
	
	SeedRandom( parameters.ints("random_seed") ); // or specify a seed here 
	
	// housekeeping 
	
	initialize_default_cell_definition();
	cell_defaults.phenotype.secretion.sync_to_microenvironment( &microenvironment ); 
	
	// Name the default cell type 
	
	cell_defaults.type = 0; 
	cell_defaults.name = "tumor cell"; 
	
	// set default cell cycle model 

	cell_defaults.functions.cycle_model = live; 
	
	// set default_cell_functions; 
	
	cell_defaults.functions.update_phenotype = NULL; 
	
	// needed for a 2-D simulation: 
	
	/* grab code from heterogeneity */ 
	
	cell_defaults.functions.set_orientation = up_orientation; 
	cell_defaults.phenotype.geometry.polarity = 1.0;
	cell_defaults.phenotype.motility.restrict_to_2D = true; 
	
	// make sure the defaults are self-consistent. 
	
	cell_defaults.phenotype.secretion.sync_to_microenvironment( &microenvironment );
	cell_defaults.phenotype.sync_to_functions( cell_defaults.functions ); 

	// set the rate terms in the default phenotype 

	// first find index for a few key variables. 
	int apoptosis_model_index = cell_defaults.phenotype.death.find_death_model_index( "Apoptosis" );
	int necrosis_model_index = cell_defaults.phenotype.death.find_death_model_index( "Necrosis" );
	static int chemical1_substrate_index = microenvironment.find_density_index( "chemical1" );
	int chemical2_substrate_index = microenvironment.find_density_index( "chemical2" ); 

	int start_index = live.find_phase_index( PhysiCell_constants::live );
	int end_index = live.find_phase_index( PhysiCell_constants::live );

	// initially no necrosis 
	cell_defaults.phenotype.death.rates[necrosis_model_index] = 0.0; 
	cell_defaults.phenotype.death.rates[apoptosis_model_index] = 0.0; 


	// set oxygen uptake / secretion parameters for the default cell type 
	cell_defaults.phenotype.secretion.uptake_rates[chemical1_substrate_index] = parameters.doubles( "chemical1_uptake_rate_coefficient" ); 
	cell_defaults.phenotype.secretion.secretion_rates[chemical1_substrate_index] = parameters.doubles( "chemical1_secretion_rate_coefficient" ); 
	cell_defaults.phenotype.secretion.saturation_densities[chemical1_substrate_index] = parameters.doubles( "chemical1_saturation_density" ); 
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!" << cell_defaults.phenotype.molecular.internalized_total_substrates << std::endl; //= 2.0; // parameters.doubles( "internal_chemical1" );	
	system("pause"); 
	
	cell_defaults.phenotype.secretion.uptake_rates[chemical2_substrate_index] = parameters.doubles( "chemical2_uptake_rate_coefficient" ); 
	cell_defaults.phenotype.secretion.secretion_rates[chemical2_substrate_index] = parameters.doubles( "chemical2_secretion_rate_coefficient" ); 
	cell_defaults.phenotype.secretion.saturation_densities[chemical2_substrate_index] = parameters.doubles( "chemical2_saturation_density" );
	//cell_defaults.phenotype.molecular.internalized_total_substrates[chemical2_substrate_index] = parameters.doubles( "internal_chemical2" );
	
	// add custom data here, if any 
	

	// Now, let's define another cell type. 
	// It's best to just copy the default and modify it. 
	
	// make this cell type randomly motile, less adhesive, greater survival, 
	// and less proliferative 
	
	secretion_cell = cell_defaults; 
	secretion_cell.type = 1; 
	secretion_cell.name = "secretion cell"; 
	
	// make sure the new cell type has its own reference phenotype
	
	secretion_cell.parameters.pReference_live_phenotype = &( secretion_cell.phenotype ); 
	
	// enable random motility 
	secretion_cell.phenotype.motility.is_motile = false; 
	
	// Set cell-cell adhesion to 5% of other cells 
	secretion_cell.phenotype.mechanics.cell_cell_adhesion_strength *= parameters.doubles( "secretion_cell_relative_adhesion" ); // 0.05; 
	
	return; 
}

void setup_microenvironment( void )
{
	
	// make sure to override and go back to 2D 
	if( default_microenvironment_options.simulate_2D == false )
	{
		std::cout << "Warning: overriding XML config option and setting to 2D!" << std::endl; 
		default_microenvironment_options.simulate_2D = true; 
	}
	

	initialize_microenvironment(); 	
	
	return; 
}

void setup_tissue( void )
{
	// create some cells near the origin
	
	Cell* pC;

	pC = create_cell(); 
	pC->assign_position( 0.0, 0.0, 0.0 );
	
	
	return; 
}

std::vector<std::string> my_coloring_function( Cell* pCell )
{
	// start with flow cytometry coloring 
/* 	pugi::xml_node node;
	bool internalization_bool = xml_get_bool_value( node, "track_internalized_substrates_in_each_agent" ); 
	std::vector<std::string> output = false_cell_coloring_cytometry(pCell); 
	std::cout<<internalization_bool<<std::endl; */
	
	
	std::vector<std::string> output = false_cell_coloring_cytometry(pCell);
	double internalization_bool = parameters.doubles( "internalization_color" );
	std::cout<<internalization_bool<<std::endl;
	
	//bookkeeping
	int chemical1_substrate_index = microenvironment.find_density_index( "chemical1" );
	int chemical2_substrate_index = microenvironment.find_density_index( "chemical2" );
	
	if (internalization_bool == 0)
    {	
	if( pCell->phenotype.death.dead == false && pCell->type == 0 )
	{
		 output[0] = "red"; 
		 output[2] = "red"; 
	}
	}
	
	
	if (internalization_bool == 1)
    {	
	if( pCell->phenotype.death.dead == false && pCell->type == 0 )
	{
		int c_ch1 = (int) round(255* (pCell->phenotype.molecular.internalized_total_substrates[chemical1_substrate_index]/10.0 ));
		std::cout<<pCell->phenotype.molecular.internalized_total_substrates[chemical1_substrate_index]<<std::endl;
		char szTempString [128];
		sprintf( szTempString , "rgb(%u,%u,%u)",0, 0, c_ch1);
		output[0].assign( szTempString );
		output[1].assign( szTempString );
		int n_ch1 = (int) round (255 * ((pCell->phenotype.molecular.internalized_total_substrates[chemical1_substrate_index])/10.0 )); 
		sprintf( szTempString , "rgb(%u,%u,%u)", 0 , 0 , n_ch1 );
		output[2].assign( szTempString );
		output[3].assign( szTempString );
	}
	}
	
	if (internalization_bool == 2)
    {	
	if( pCell->phenotype.death.dead == false && pCell->type == 0 )
	{
		int c_ch2 = (int) round(255* ((pCell->phenotype.molecular.internalized_total_substrates[chemical2_substrate_index])/10.0 )); 
		char szTempString [128];
		sprintf( szTempString , "rgb(%u,%u,%u)",0, 0, c_ch2);
		output[0].assign( szTempString );
		output[1].assign( szTempString );
		int n_ch2 = (int) round (255 * ((pCell->phenotype.molecular.internalized_total_substrates[chemical2_substrate_index])/10.0 )); 
		sprintf( szTempString , "rgb(%u,%u,%u)", 0 , 0 , n_ch2 );
		output[2].assign( szTempString );
		output[3].assign( szTempString );
	}
	}
	
	return output; 
}
