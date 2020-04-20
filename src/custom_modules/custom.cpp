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
    
    
	static int chemical1_substrate_index = microenvironment.find_density_index( "uptaken" );
	static int chemical2_substrate_index = microenvironment.find_density_index( "secreted" ); 

	int start_index = live.find_phase_index( PhysiCell_constants::live );
	int end_index = live.find_phase_index( PhysiCell_constants::live );

	// initially no necrosis 
	cell_defaults.phenotype.death.rates[necrosis_model_index] = 0.0; 
	cell_defaults.phenotype.death.rates[apoptosis_model_index] = 0.0; 


	// set oxygen uptake / secretion parameters for the default cell type 
	cell_defaults.phenotype.secretion.uptake_rates[chemical1_substrate_index] = parameters.doubles( "uptaken_uptake_rate_coefficient" ); 
	cell_defaults.phenotype.secretion.secretion_rates[chemical1_substrate_index] = parameters.doubles( "uptaken_secretion_rate_coefficient" ); 
	cell_defaults.phenotype.secretion.saturation_densities[chemical1_substrate_index] = parameters.doubles( "uptaken_saturation_density" ); 
	// std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!" << cell_defaults.phenotype.molecular.internalized_total_substrates << std::endl; //= 2.0; // parameters.doubles( "internal_chemical1" );	
	// system("pause"); 
	
	cell_defaults.phenotype.secretion.uptake_rates[chemical2_substrate_index] = parameters.doubles( "secreted_uptake_rate_coefficient" ); 
	cell_defaults.phenotype.secretion.secretion_rates[chemical2_substrate_index] = parameters.doubles( "secreted_secretion_rate_coefficient" ); 
	cell_defaults.phenotype.secretion.saturation_densities[chemical2_substrate_index] = parameters.doubles( "secreted_saturation_density" );
	// cell_defaults.phenotype.molecular.internalized_total_substrates[chemical2_substrate_index] = parameters.doubles( "internal_chemical2" );
    // std::cout << cell_defaults.phenotype.molecular.internalized_total_substrates[chemical2_substrate_index] << std::endl;
    
    
    
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

	static int chemical1_substrate_index = microenvironment.find_density_index( "uptaken" );
	static int chemical2_substrate_index = microenvironment.find_density_index( "secreted" ); 

	pC = create_cell(); 
	pC->assign_position( 0.0, 0.0, 0.0 );
	
    pC->phenotype.molecular.internalized_total_substrates[chemical1_substrate_index] = parameters.doubles( "internal_uptaken" );
    pC->phenotype.molecular.internalized_total_substrates[chemical2_substrate_index] = parameters.doubles( "internal_secreted" );
	
	return; 
}

std::vector<std::string> my_coloring_function( Cell* pCell )
{

	std::vector<std::string> output = false_cell_coloring_cytometry(pCell);
	double internalization_flag = parameters.doubles( "internalization_color" );
	
	//bookkeeping
	int chemical1_substrate_index = microenvironment.find_density_index( "uptaken" );
	int chemical2_substrate_index = microenvironment.find_density_index( "secreted" );
	
	if (internalization_flag == 0)
    {	
	if( pCell->phenotype.death.dead == false && pCell->type == 0 )
	{
		 output[0] = "red"; 
		 output[2] = "red"; 
	}
	}
	
    //Blue
    double Ry1_1=0.0;
    double Ry2_1=181.0;
    double Gy1_1=17.0;
    double Gy2_1=186.0;
    double By1_1=255.0;
    double By2_1=255.0;
	double x1_1=0.0;
    double x2_1=10.0;
    double z1_1 = pCell->phenotype.molecular.internalized_total_substrates[chemical1_substrate_index];
    
    //Red
    double Ry1_2=255.0;
    double Ry2_2=255.0;
    double Gy1_2=0.0;
    double Gy2_2=159.0;
    double By1_2=0.0;
    double By2_2=159.0;
	double x1_2=0.0;
    double x2_2=10.0;
    double z1_2 = pCell->phenotype.molecular.internalized_total_substrates[chemical2_substrate_index];
    
    
	if (internalization_flag == 1)
    {
	if( pCell->phenotype.death.dead == false && pCell->type == 0 )
	{
        int R_ch1 = (int) 255.0-round((z1_1 - x1_1)/(x2_1 - x1_1)*(Ry2_1 - Ry1_1) - Ry1_1);
        int G_ch1 = (int) 255.0-round((z1_1 - x1_1)/(x2_1 - x1_1)*(Gy2_1 - Gy1_1) - Gy1_1);
        int B_ch1 = (int) 255.0-round((z1_1 - x1_1)/(x2_1 - x1_1)*(By2_1 - By1_1) - By1_1);
		// std::cout<<pCell->phenotype.molecular.internalized_total_substrates[chemical1_substrate_index]<<std::endl;
		char szTempString [128];
		sprintf( szTempString , "rgb(%u,%u,%u)",R_ch1, G_ch1, B_ch1);
		output[0].assign( szTempString );
        int R_ch2 = (int) 255.0-round((z1_2 - x1_2)/(x2_2 - x1_2)*(Ry2_2 - Ry1_2) - Ry1_2);
        int G_ch2 = (int) 255.0-round((z1_2 - x1_2)/(x2_2 - x1_2)*(Gy2_2 - Gy1_2) - Gy1_2);
        int B_ch2 = (int) 255.0-round((z1_2 - x1_2)/(x2_2 - x1_2)*(By2_2 - By1_2) - By1_2);
        //std::cout<<pCell->phenotype.molecular.internalized_total_substrates[chemical2_substrate_index]<<std::endl;
		sprintf( szTempString , "rgb(%u,%u,%u)", R_ch2 , G_ch2 , B_ch2 );
		output[2].assign( szTempString );
	}
	}

	return output; 
}
