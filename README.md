# ConfigReader
A Simple Configuration Reader Library by C++

# Include
1. include "ConfigReader.h" Header to the project 
2. add all files under src to the compile file

# Usage

Initilize a Config Reader, and configuration will be loaded.
```
ConfigReader cr("demo/demo.conf");
```
Get a value from Configuration by key
```
cr.GetConfig("Address");
```
Or using [] 
```
cr["Author"];
```

If key does not exist, the value will be nullptr 

Set the Config by
```
cr.SetConfig(name, value);
```

Export the config into another file by
```
cr.writeConfig(address);
```

# Config Format
"=" seperate a pair of name and value for each line
"#" starts a comment

```
Version=1.1.4
path=./src/
# This is a comment
Enable_https=True
```

# Further Function
- Identify different type [Number, String, Bool, etc]
- Give option to handle lower/upper non-sensitive case
- Modify original configuration file

# Contributing
Issues are welcome


