# Commandline-Parameter-Manager
A simple commandline argument manager. 

This allows the user to give the program a string of commandline arguments and they will be automatically identified and passed to the corresponding functions. The order in which the arguments are written doesn't matter and not all arguments have to be specified. Interpretation o fthe values is up to the user. The user has to create a function for each argument that handles the value. 

<h3> EXAMPLE: </h3>

<p>
<b>functions</b><br>
saveArgument(std::string value);<br>
speedArgument(std::string value);<br>
nameArgument(std::string value);<br>
</p>
<p>
<b>command line arguments</b>
name=Richard save=true kefir=drink<br>
</p>
<p>
name=Richard is arg[0] cstring and its value[0] = "Richard"<br>
speed=10.0 is arg[1] cstring and its value[1] = "10.0"<br>
kefir=drink is arg[2] cstring and its value[2] = "drink"<br>
</p>
<p>
<b>executes functions</b><br>
nameArgument("Richard");<br>
speedArgument("10.0");<br>
exception kefir is unknown parameter<br>
</p>
<p>
I know Cmake is a bit overkill at this size of a project (it was for learning purposes). <br>
Maybe I will make it a header only in the future.
</p>
