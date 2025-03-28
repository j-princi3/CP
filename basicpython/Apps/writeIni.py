import configparser

cfgfile = open("newIni.ini",'w')
Config = configparser.ConfigParser()

# add the settings to the structure of the file, and lets write it out...
Config.add_section('Company')
Config.set('Company','Name','Genesis InSoft')
Config.set('Company','Location', 'Hyderabad')

Config.add_section('Employee')
Config.set('Employee','Name','Ravi')
Config.set('Employee','Department', 'HR')
Config.write(cfgfile)
cfgfile.close()