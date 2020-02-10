 
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

        param_name1 = Button(description='random_seed', disabled=True, layout=name_button_layout)
        param_name1.style.button_color = 'lightgreen'

        self.random_seed = IntText(
          value=0,
          step=1,
          style=style, layout=widget_layout)

        param_name2 = Button(description='chemical1_uptake_rate_coefficient', disabled=True, layout=name_button_layout)
        param_name2.style.button_color = 'tan'

        self.chemical1_uptake_rate_coefficient = FloatText(
          value=0.1,
          step=0.01,
          style=style, layout=widget_layout)

        param_name3 = Button(description='chemical1_secretion_rate_coefficient', disabled=True, layout=name_button_layout)
        param_name3.style.button_color = 'lightgreen'

        self.chemical1_secretion_rate_coefficient = FloatText(
          value=0.0,
          step=0.01,
          style=style, layout=widget_layout)

        param_name4 = Button(description='chemical1_saturation_density', disabled=True, layout=name_button_layout)
        param_name4.style.button_color = 'tan'

        self.chemical1_saturation_density = FloatText(
          value=10.0,
          step=1,
          style=style, layout=widget_layout)

        param_name5 = Button(description='internal_chemical1', disabled=True, layout=name_button_layout)
        param_name5.style.button_color = 'lightgreen'

        self.internal_chemical1 = FloatText(
          value=2.0,
          step=0.1,
          style=style, layout=widget_layout)

        param_name6 = Button(description='chemical2_uptake_rate_coefficient', disabled=True, layout=name_button_layout)
        param_name6.style.button_color = 'tan'

        self.chemical2_uptake_rate_coefficient = FloatText(
          value=0.0,
          step=0.01,
          style=style, layout=widget_layout)

        param_name7 = Button(description='chemical2_secretion_rate_coefficient', disabled=True, layout=name_button_layout)
        param_name7.style.button_color = 'lightgreen'

        self.chemical2_secretion_rate_coefficient = FloatText(
          value=0.5,
          step=0.1,
          style=style, layout=widget_layout)

        param_name8 = Button(description='chemical2_saturation_density', disabled=True, layout=name_button_layout)
        param_name8.style.button_color = 'tan'

        self.chemical2_saturation_density = FloatText(
          value=10.0,
          step=1,
          style=style, layout=widget_layout)

        param_name9 = Button(description='internal_chemical2', disabled=True, layout=name_button_layout)
        param_name9.style.button_color = 'lightgreen'

        self.internal_chemical2 = FloatText(
          value=10.0,
          step=1,
          style=style, layout=widget_layout)

        param_name10 = Button(description='internalization_color', disabled=True, layout=name_button_layout)
        param_name10.style.button_color = 'tan'

        self.internalization_color = FloatText(
          value=1,
          step=0.1,
          style=style, layout=widget_layout)

        units_button1 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button1.style.button_color = 'lightgreen'
        units_button2 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button2.style.button_color = 'tan'
        units_button3 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button3.style.button_color = 'lightgreen'
        units_button4 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button4.style.button_color = 'tan'
        units_button5 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button5.style.button_color = 'lightgreen'
        units_button6 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button6.style.button_color = 'tan'
        units_button7 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button7.style.button_color = 'lightgreen'
        units_button8 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button8.style.button_color = 'tan'
        units_button9 = Button(description='1/min', disabled=True, layout=units_button_layout) 
        units_button9.style.button_color = 'lightgreen'
        units_button10 = Button(description='', disabled=True, layout=units_button_layout) 
        units_button10.style.button_color = 'tan'

        desc_button1 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button1.style.button_color = 'lightgreen'
        desc_button2 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button2.style.button_color = 'tan'
        desc_button3 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button3.style.button_color = 'lightgreen'
        desc_button4 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button4.style.button_color = 'tan'
        desc_button5 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button5.style.button_color = 'lightgreen'
        desc_button6 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button6.style.button_color = 'tan'
        desc_button7 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button7.style.button_color = 'lightgreen'
        desc_button8 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button8.style.button_color = 'tan'
        desc_button9 = Button(description='', disabled=True, layout=desc_button_layout) 
        desc_button9.style.button_color = 'lightgreen'
        desc_button10 = Button(description='Colorization (0->Default, 1->Chemical 1, 2->Chemical 2', disabled=True, layout=desc_button_layout) 
        desc_button10.style.button_color = 'tan'

        row1 = [param_name1, self.random_seed, units_button1, desc_button1] 
        row2 = [param_name2, self.chemical1_uptake_rate_coefficient, units_button2, desc_button2] 
        row3 = [param_name3, self.chemical1_secretion_rate_coefficient, units_button3, desc_button3] 
        row4 = [param_name4, self.chemical1_saturation_density, units_button4, desc_button4] 
        row5 = [param_name5, self.internal_chemical1, units_button5, desc_button5] 
        row6 = [param_name6, self.chemical2_uptake_rate_coefficient, units_button6, desc_button6] 
        row7 = [param_name7, self.chemical2_secretion_rate_coefficient, units_button7, desc_button7] 
        row8 = [param_name8, self.chemical2_saturation_density, units_button8, desc_button8] 
        row9 = [param_name9, self.internal_chemical2, units_button9, desc_button9] 
        row10 = [param_name10, self.internalization_color, units_button10, desc_button10] 

        box_layout = Layout(display='flex', flex_flow='row', align_items='stretch', width='100%')
        box1 = Box(children=row1, layout=box_layout)
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
          box1,
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
        self.random_seed.value = int(uep.find('.//random_seed').text)
        self.chemical1_uptake_rate_coefficient.value = float(uep.find('.//chemical1_uptake_rate_coefficient').text)
        self.chemical1_secretion_rate_coefficient.value = float(uep.find('.//chemical1_secretion_rate_coefficient').text)
        self.chemical1_saturation_density.value = float(uep.find('.//chemical1_saturation_density').text)
        self.internal_chemical1.value = float(uep.find('.//internal_chemical1').text)
        self.chemical2_uptake_rate_coefficient.value = float(uep.find('.//chemical2_uptake_rate_coefficient').text)
        self.chemical2_secretion_rate_coefficient.value = float(uep.find('.//chemical2_secretion_rate_coefficient').text)
        self.chemical2_saturation_density.value = float(uep.find('.//chemical2_saturation_density').text)
        self.internal_chemical2.value = float(uep.find('.//internal_chemical2').text)
        self.internalization_color.value = float(uep.find('.//internalization_color').text)


    # Read values from the GUI widgets to enable editing XML
    def fill_xml(self, xml_root):
        uep = xml_root.find('.//microenvironment_setup')  # find unique entry point
        vp = []   # pointers to <variable> nodes
        if uep:
            for var in uep.findall('variable'):
                vp.append(var)

        uep = xml_root.find('.//user_parameters')  # find unique entry point
        uep.find('.//random_seed').text = str(self.random_seed.value)
        uep.find('.//chemical1_uptake_rate_coefficient').text = str(self.chemical1_uptake_rate_coefficient.value)
        uep.find('.//chemical1_secretion_rate_coefficient').text = str(self.chemical1_secretion_rate_coefficient.value)
        uep.find('.//chemical1_saturation_density').text = str(self.chemical1_saturation_density.value)
        uep.find('.//internal_chemical1').text = str(self.internal_chemical1.value)
        uep.find('.//chemical2_uptake_rate_coefficient').text = str(self.chemical2_uptake_rate_coefficient.value)
        uep.find('.//chemical2_secretion_rate_coefficient').text = str(self.chemical2_secretion_rate_coefficient.value)
        uep.find('.//chemical2_saturation_density').text = str(self.chemical2_saturation_density.value)
        uep.find('.//internal_chemical2').text = str(self.internal_chemical2.value)
        uep.find('.//internalization_color').text = str(self.internalization_color.value)
