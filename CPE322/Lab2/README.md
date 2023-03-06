# Lab 2: Command Line + Chat GPT Explanation

For this lab, we were tasked with running simple command line commands using a Rasberry PI. Unfortunately, I misplaced my Rasberry PI, so to add some complexity to it by creating a python script that will automatically run and explain the commands that I run using the [Chat GPT API](https://platform.openai.com/docs/guides/chat/introduction). (Also because I want to learn how to use their API for my personal projects).

## Part 1: Getting the Chat GPT API to work

I followed the instructions on the [Chat GPT API](https://platform.openai.com/docs/guides/chat/introduction) website to get the API to work. I had to create an account and then create an API key. I then used the following code to install the API:

```bash
$ pip install openai
```

After creating a folder called 'OPENAI_API_KEY.txt' in my Documents folder, I was able to link the API to my python script with the following commands.

```python
# Set up the Open AI API

#Open the api key from my documents
with open(os.path.expanduser("~/Documents/OPENAI_API_KEY.txt")) as f:
    openai.api_key = f.read().strip()


#Set up the Organization
openai.organization
```

I was able to test the API by running the following code:

```python
output = openai.ChatCompletion.create(
  model="gpt-3.5-turbo",
  messages=[
        {"role": "system", "content": "You are a helpful assistant."}, #Set up the role of the assistant
        {"role": "user", "content": "Where was the Olympics in 2020 played?"} #User Input
    ]
)
print(output.choices[0].message.content)
```

This outputted the following:

```bash
The Olympics that were supposed to take place in 2020 were scheduled to be held in Tokyo, Japan. However, due to the COVID-19 pandemic, they were postponed to July 23-August 8, 2021.
```

## Part 3: Setting up the program

This part wil involve telling Chat GPT it's role and setting up the function to get the explanation for a specific command.

The openai.ChatCompletion.create() function requires a table called "messages" that contains the role of the assistant and the user input. This initial "messages" table was set up as follows:

```python
messages = [
    {"role": "system", "content": "You are a helpful assistant that will be used to explain several terminal commands."},
]
```

The function that will be used to get the explanation for a specific command is as follows:

```python
def getCommandInfo(command):
    output = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages= messages+[{"role": "user", "content": command}]
    )
    return output.choices[0].message.content
```

## Part 2: Running the commands

I set up a table with the given commands and looped through them, using os.system(commandName) to get the terminal output for each command.

```

```

The Content of output.txt is as follows:
