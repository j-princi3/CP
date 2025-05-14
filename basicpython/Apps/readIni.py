import configparser

def ConfigSectionMap(section):
  dict1 = {}
  options = Config.options(section)
  print(options)
  for option in options:
    try:
      dict1[option] = Config.get(section, option)
      if dict1[option] == -1:
        DebugPrint("skip: %s" % option)
    except:
      print("exception on %s!" % option)
      dict1[option] = None
  return dict1

Config = configparser.ConfigParser()
print(Config.read("odbcinst.ini"))

print(Config.sections())

# Returns a specific value of key from a section
val = Config.get("Driver1", '32Bit')
print(val)
val = Config.get("Driver2", 'dll')
print(val)

dict = ConfigSectionMap("Driver3")
print(dict['dll'])