 
# This file is auto-generated from a Python script that parses a PhysiCell configuration (.xml) file.
#
# Edit at your own risk.
#
import os
from ipywidgets import Label,Text,Checkbox,Button,HBox,VBox,FloatText,IntText,BoundedIntText,BoundedFloatText,Layout,Box
    
class UserTab(object):

    def __init__(self):
        
        micron_units = Label('micron')   # use "option m" (Mac, for micro symbol)

        constWidth = '180px'
        tab_height = '500px'
        stepsize = 10

        #style = {'description_width': '250px'}
        style = {'description_width': '25%'}
        layout = {'width': '400px'}

        name_button_layout={'width':'25%'}
        widget_layout = {'width': '15%'}
        units_button_layout ={'width':'15%'}
        desc_button_layout={'width':'45%'}
        divider_button_layout={'width':'40%'}

        param_name1 = Button(description='uptaken_uptake_rate_coefficient', disabled=True, layout=name_button_layout)
        param_name1.style.button_color = 'tan'

        self.uptaken_uptake_rate_coefficient = FloatText(
          value=0.0000075,
          step=1e-06,
          style=style, layout=widget_layout)

        param_name2 = Button(description='uptaken_secretion_rate_coefficient', disabled=True, layout=name_button_layout)
        param_name2.style.button_color = 'lightgreen'

        self.uptaken_secretion_rate_coefficient = FloatText(
          value=0.0,
          step=0.01,
          style=style, layout=widget_layout)

        param_name3 = Button(description='uptaken_saturation_density', disabled=True, layout=name_button_layout)
        param_name3.style.button_color = 'tan'

        self.uptaken_saturation_density = FloatText(
          value=10.0,
          step=1,
          style=style, layout=widget_layout)

        param_name4 = Button(description='internal_uptaken', disabled=True, layout=name_button_layout)
        param_name4.style.button_color = 'lightgreen'

        self.internal_uptaken = FloatText(
          value=0.0,
          step=0.01,
          style=style, layout=widget_layout)

        param_name5 = Button(description='secreted_uptake_rate_coefficient', disabled=True, layout=name_button_layout)
        param_name5.style.button_color = 'tan'

        self.secreted_uptake_rate_coefficient = FloatText(
          value=0.0,
          step=0.01,
          style=style, layout=widget_layout)

        param_name6 = Button(description='secreted_secretion_rate_coefficient', disabled=True, layout=name_button_layout)
        param_name6.style.button_color = 'lightgreen'

        self.secreted_secretion_rate_coefficient = FloatText(
          value=0.0000075,
          step=1e-06,
          style=style, layout=widget_layout)

        param_name7 = Button(description='secreted_saturation_density', disabled=True, layout=name_button_layout)
        param_name7.style.button_color = 'tan'

        self.secreted_saturation_density = FloatText(
          value=10.0,
          step=1,
          style=style, layout=widget_layout)

        param_name8 = Button(description='internal_secreted', disabled=True, layout=name_button_layout)
        param_name8.style.button_color = 'lightgreen'

        self.internal_secreted = FloatText(
          value=10.0,
          step=1,
          style=style, layout=widget_layout)

        param_name9 = Button(description='internalization_color', disabled=True, layout=name_button_layout)
        param_name9.style.button_color = 'tan'

        self.internalization_color = Checkbox(
          value=False,
          style=style, layout=widget_layout)

        units_button1 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button1.style.button_color = 'tan'
        units_button2 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button2.style.button_color = 'lightgreen'
        units_button3 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button3.style.button_color = 'tan'
        units_button4 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button4.style.button_color = 'lightgreen'
        units_button5 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button5.style.button_color = 'tan'
        units_button6 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button6.style.button_color = 'lightgreen'
        units_button7 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button7.style.button_color = 'tan'
        units_button8 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button8.style.button_color = 'lightgreen'
        units_button9 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button9.style.button_color = 'tan'

        desc_button2 = Button(description='uptake rate per min for uptaken chemical (Default = 0.0000075)' , tooltip='uptake rate per min for uptaken chemical (Default = 0.0000075)', disabled=True, layout=desc_button_layout) 
        desc_button2.style.button_color = 'tan'
        desc_button3 = Button(description='secreteion rate per min for uptaken chemical (Default = 0.0)' , tooltip='secreteion rate per min for uptaken chemical (Default = 0.0)', disabled=True, layout=desc_button_layout) 
        desc_button3.style.button_color = 'lightgreen'
        desc_button4 = Button(description='saturation density for uptaken chemical (Default = 10.0)' , tooltip='saturation density for uptaken chemical (Default = 10.0)', disabled=True, layout=desc_button_layout) 
        desc_button4.style.button_color = 'tan'
        desc_button5 = Button(description='initial internalized uptaken chemical (Default = 0.0)' , tooltip='initial internalized uptaken chemical (Default = 0.0)', disabled=True, layout=desc_button_layout) 
        desc_button5.style.button_color = 'lightgreen'
        desc_button6 = Button(description='uptake rate per min for secreted chemical (Default = 0.0)' , tooltip='uptake rate per min for secreted chemical (Default = 0.0)', disabled=True, layout=desc_button_layout) 
        desc_button6.style.button_color = 'tan'
        desc_button7 = Button(description='secreteion rate per min for secreted chemical (Default = 0.0000075)' , tooltip='secreteion rate per min for secreted chemical (Default = 0.0000075)', disabled=True, layout=desc_button_layout) 
        desc_button7.style.button_color = 'lightgreen'
        desc_button8 = Button(description='saturation density for secreted chemical (Default = 10.0)' , tooltip='saturation density for secreted chemical (Default = 10.0)', disabled=True, layout=desc_button_layout) 
        desc_button8.style.button_color = 'tan'
        desc_button9 = Button(description='initial internalized secreted chemical (Default = 10.0)' , tooltip='initial internalized secreted chemical (Default = 10.0)', disabled=True, layout=desc_button_layout) 
        desc_button9.style.button_color = 'lightgreen'
        desc_button10 = Button(description='Colorization (false->Default (Red), true->Internal Chemicals 2' , tooltip='Colorization (false->Default (Red), true->Internal Chemicals 2', disabled=True, layout=desc_button_layout) 
        desc_button10.style.button_color = 'tan'

        row2 = [param_name1, self.uptaken_uptake_rate_coefficient, units_button1, desc_button2] 
        row3 = [param_name2, self.uptaken_secretion_rate_coefficient, units_button2, desc_button3] 
        row4 = [param_name3, self.uptaken_saturation_density, units_button3, desc_button4] 
        row5 = [param_name4, self.internal_uptaken, units_button4, desc_button5] 
        row6 = [param_name5, self.secreted_uptake_rate_coefficient, units_button5, desc_button6] 
        row7 = [param_name6, self.secreted_secretion_rate_coefficient, units_button6, desc_button7] 
        row8 = [param_name7, self.secreted_saturation_density, units_button7, desc_button8] 
        row9 = [param_name8, self.internal_secreted, units_button8, desc_button9] 
        row10 = [param_name9, self.internalization_color, units_button9, desc_button10] 

        box_layout = Layout(display='flex', flex_flow='row', align_items='stretch', width='100%')
        box2 = Box(children=row2, layout=box_layout)
        box3 = Box(children=row3, layout=box_layout)
        box4 = Box(children=row4, layout=box_layout)
        box5 = Box(children=row5, layout=box_layout)
        box6 = Box(children=row6, layout=box_layout)
        box7 = Box(children=row7, layout=box_layout)
        box8 = Box(children=row8, layout=box_layout)
        box9 = Box(children=row9, layout=box_layout)
        box10 = Box(children=row10, layout=box_layout)

        self.tab = VBox([
          box2,
          box3,
          box4,
          box5,
          box6,
          box7,
          box8,
          box9,
          box10,
        ])

    # Populate the GUI widgets with values from the XML
    def fill_gui(self, xml_root):
        uep = xml_root.find('.//microenvironment_setup')  # find unique entry point
        vp = []   # pointers to <variable> nodes
        if uep:
            for var in uep.findall('variable'):
                vp.append(var)

        uep = xml_root.find('.//user_parameters')  # find unique entry point
        self.uptaken_uptake_rate_coefficient.value = float(uep.find('.//uptaken_uptake_rate_coefficient').text)
        self.uptaken_secretion_rate_coefficient.value = float(uep.find('.//uptaken_secretion_rate_coefficient').text)
        self.uptaken_saturation_density.value = float(uep.find('.//uptaken_saturation_density').text)
        self.internal_uptaken.value = float(uep.find('.//internal_uptaken').text)
        self.secreted_uptake_rate_coefficient.value = float(uep.find('.//secreted_uptake_rate_coefficient').text)
        self.secreted_secretion_rate_coefficient.value = float(uep.find('.//secreted_secretion_rate_coefficient').text)
        self.secreted_saturation_density.value = float(uep.find('.//secreted_saturation_density').text)
        self.internal_secreted.value = float(uep.find('.//internal_secreted').text)
        self.internalization_color.value = ('true' == (uep.find('.//internalization_color').text.lower()) )


    # Read values from the GUI widgets to enable editing XML
    def fill_xml(self, xml_root):
        uep = xml_root.find('.//microenvironment_setup')  # find unique entry point
        vp = []   # pointers to <variable> nodes
        if uep:
            for var in uep.findall('variable'):
                vp.append(var)

        uep = xml_root.find('.//user_parameters')  # find unique entry point
        uep.find('.//uptaken_uptake_rate_coefficient').text = str(self.uptaken_uptake_rate_coefficient.value)
        uep.find('.//uptaken_secretion_rate_coefficient').text = str(self.uptaken_secretion_rate_coefficient.value)
        uep.find('.//uptaken_saturation_density').text = str(self.uptaken_saturation_density.value)
        uep.find('.//internal_uptaken').text = str(self.internal_uptaken.value)
        uep.find('.//secreted_uptake_rate_coefficient').text = str(self.secreted_uptake_rate_coefficient.value)
        uep.find('.//secreted_secretion_rate_coefficient').text = str(self.secreted_secretion_rate_coefficient.value)
        uep.find('.//secreted_saturation_density').text = str(self.secreted_saturation_density.value)
        uep.find('.//internal_secreted').text = str(self.internal_secreted.value)
        uep.find('.//internalization_color').text = str(self.internalization_color.value)
