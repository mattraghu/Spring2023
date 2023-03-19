# Lab 7 : ThingSpeak and Google Sheets API (w/ Chat GPT API )

## Part 1 : ThingSpeak

ThingSpeak is a cloud based service that allows users to collect data and upload it to a server. For this part of the project, I used the ThingSpeak API to upload CPU and memory usage data from my Macbook to a ThingSpeak channel. The data was then graphed using the ThingSpeak API.

### Step 1 : Setting Up ThingSpeak

This involved creating a ThingSpeak account and creating a channel. The channel was set up to have two fields, one for CPU usage and one for memory usage. The channel was set up to have a refresh rate of 15 seconds.

### Step 2 : Uploading Data

This involved using the **thingspeak_cpu_loop.py** script from the IOT Repository to upload data to the channel. The script was modified to use my channel's API key and to collect and upload data every 15 seconds (as opposed to every 60 seconds).

Here is the result:
![ThingSpeak](Media/CPULoop.gif)

## Part 2 : Google Sheets

The Google Sheets API is able to communicate and interact with a Google Sheets.

For this part of the lab, I created a program that uses both the **Google Sheets API** and **Chat GPT API** to read and modify a google sheets based on the prompt the user gives it.

### Step 1 : Setting Up Google Sheets

The steps from [this website](https://robocorp.com/docs/development-guide/google-sheets/interacting-with-google-sheets) were followed to set up a Google Sheets API. The Google Sheets API could then be used to read and write to a Google Sheets using a credentials file.

### Step 2 : Setting Up Chat GPT

The steps to setup the Chat GPT API are explained in prior labs. The Organization and API key were both obtained from the Chat GPT website and are used to access the API.

### Step 3 : Creating the Program

The program can be vieweed in the **ChatGPTSheets.ipynb** file.

Essentially, Chat GPT is told to generate a response to a prompt based on a given spreadsheet. The response is then formatted back into a spreadsheet and written to the second sheet in the spreadsheet.

In this example I give it a spreadsheet consisting of all the periodic table of elements, their symbol and atomic mass; and I ask it to add two other columns consisting of the element's full name and dicovery date.

Here is the result:
![ChatGPT](Media/ChatGPTSheetsExample.gif)

Note: The program takes a bit to run (~1 minute for this example) because of the large text input to the Chat GPT API.

## Conclusion

Ultimately, ThingSpeak seems like a great tool for collecting and graphing data on a server without having to write a lot of code.

The Google Sheets API seems like a wonderful tool for interacting with Google Sheets. My program that uses the Chat GPT API and Google Sheets API is a great example of how the Google Sheets API can be used to interact with other APIs. While it may not be the most userfriendly (yet) it is an interesting testament to how developers can apply these APIs to create new and useful tools.
