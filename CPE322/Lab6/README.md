# Lab 6 : Node.js and Pystache

## Part 1 : Node.js

This part of the lab involves sing Node.js to create and run simple web servers from various java script files.

### Step 1 : Install Node.js

The Node Js installer was downloaded from the [Node.js website](https://nodejs.org/en/download/). The installer was run and the default options were selected.

### Step 2 : Hello.js

Hello.js was ran from the command line and produced the following output:

![Hello.js](Media/HelloWorldJs.gif)

This was achieved by utilizing the `http.createServer` function to create a server and the `listen` function to listen on port 8080. The `writeHead` function was used to set the status code and the `end` function was used to end the response.

### Step 3 : Http.js

The http.js file was ran the same way with this result:

![Http.js](Media/HttpJs.gif)

This script works almost the same way except it uses the `fs` module to read into a file called `test.txt`. This file contains an integer amount that, every time the server at port 8080 is accessed, is incremented by one. The `fs.writeFile` function is used to write the new value back into the file. The amount of times the server has been accessed is displayed on the webpage.

##Part 2 : Pystache

### Step 1 : Install Pystache

Pystach was installed from the command line with the following command:

```bash
sudo pip3 install pystache
```

### Step 2 : say_hello.py

The say_hello.py file was ran with the following result:

![say_hello.py](Media/SayHello.gif)

This script uses the `pystache` module to render a python file.
It works by using the `pystache.render` function to render a string with the given data. The `pystache.Renderer` function is used to render a template file. The `pystache.parse` function is used to parse a template file and the `pystache.render` function is used to render the parsed template file.

## Part 3 : Conclusion

Both of these tools seem like great alternatives for creating web servers and web pages. Node.js seems great if you already are fluent with javascript, and Pystache seems great if you are already fluent with python.

Ultimately, I think I would prefer pytache over Node.js because I am more familiar with python than javascript. However, I think that Node.js would be a great tool to learn if I ever wanted to create a web server.
