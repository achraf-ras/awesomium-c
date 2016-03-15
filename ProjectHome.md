## Overview ##
[Awesomium](http://www.khrona.com) is a thin wrapper around chromium/webkit which allows for offscreen rendering of web content to be easily integrated in other applications, e.g. games. The official Awesomium API is C++ only so this project aims at creating a full, easy to use (**cough**) C-API on top of the original C++ API.

A couple of points

  * 99% of the C++ API is wrapped except resource interceptors
  * Each class in the original API is wrapped via awe\_CLASSNAME\_methodname C procedures/functions. If you follow this pattern you can refer to the official C++ documentation.
  * JSValue::Object, JSValue::Array and JSArguments are exposed in a minimal way throuw the awe\_Object\_XXX, awe\_Array\_xxx and awe\_JSArguments\_XXX procedures/functions
  * JSValues directly returned by functions must be freed via awe\_JSValue\_delete as they are deep copies of the original C++ side JSValues.
  * I currently use wchar\_t for all unicode strings. this might need to be changed for a Mac port. I also expose a procedure that directly takes WPARAM/LPARAM arguments for injecting keyboard events, something that might not go down well on a Mac :p
  * I added a couple of methods for keyboard event injection to ease the pain a little. The original API is a little cumbersome.
  * i should probably typedef things like WebCoreC, WebViewC and so on. To lazy atm.

## Setup and Compilation ##
Compiling the C-wrapper works like this:

  * Check out the SVN trunk
  * Get Microsoft Visual C++ 2008 Express or later
  * Open the awesomium-c solution and compile it
  * Depending on the configuration you will get the shared lib called awesomiumc.dll and the import library called awesomiumc.lib in either the Debug/ or Release/ folder.

Setting up your own project goes like this:
  * Copy over the awesomiumc.h file to your project or set the include directories of your project to point at the location where that file is stored
  * Add awesomiumc.lib to the linker configuration, again making sure that the folder where it is located is in the linker's search path
  * include the header and code away

For debugging/running you'll need the following files besides your exe file

  * Awesomium.dll
  * awesomiumc.dll
  * AwesomiumProcess.exe
  * The locales/ folder (really, you need it)
  * icudt42.dll

## Examples ##
You can find a simple C project in the awesomiumc-tests folder (also part of the solution).

Additionally i created a [Freebasic](http://www.freebasic.net) header file that will allow you to use it in that language as well. The project comes with two tests, base\_test.bas which is a 1:1 copy of the awesomiumc-tests project in Freebasic, and gltest.bas which is a little bit more elaborate. To compile either of these two projects just invoke Freebasic like this on the CLI

```
fbc <source_file> -p <dir-where-awesomiumc.lib-is> -l awesomiumc
```

The freebasic code can be found in the freebasic/ directory.

That's pretty much it. Again, make sure to have all the other shared libs and exe files near your apps exe file so that things get loaded properly.

## Java Bindings ##
I also write Java bindings via JNA. They are part of [libgdx](http://code.google.com/p/libgdx/). The bindings are totally self-contained though and only depend on JNA and the Awesomium shared libraries (which are packed inside the Jar for convenience). You can check out the code via SVN from http://libgdx.googlecode.com/svn/trunk/extensions/awesomium/. There's a test project with dependencies on libgdx in there as well, in order to run it check out the complete trunk.

## License ##
I put this under the AGPL for now (yeah i'm bad). Send me a mail if you need a different license.