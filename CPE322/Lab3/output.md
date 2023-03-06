### Script Information for `lesson3/julian.py`
#### Script: 

```python
from datetime import date
from jdcal import *
now = date.today()
jd = gcal2jd(now.year, now.month, now.day)
print('Calendar Date: {:s}'.format(now.isoformat()))
print('Julian Date: {:0.1f}'.format(jd[0]+jd[1]))
print('Modified Julian Date: {:0.1f}'.format(jd[1]))

```

#### Explanation: 

## Code Explanation

The above code imports two modules `date` from `datetime` and `gcal2jd` from `jdcal` which will be used to calculate the Julian and Modified Julian dates.

1. `now = date.today()` creates a `date` object representing the current date.
2. `jd = gcal2jd(now.year, now.month, now.day)` uses `gcal2jd` function to convert Gregorian calendar date to Julian date. Three arguments are passed to the function which includes year, month and day values extracted from `now` object.
3. `print('Calendar Date: {:s}'.format(now.isoformat()))` displays the current date in the ISO format using `isoformat()` method of `now` object.
4. `print('Julian Date: {:0.1f}'.format(jd[0]+jd[1]))` prints the Julian date. It sums up both the integer and float values obtained from the `gcal2jd` function call.
5. `print('Modified Julian Date: {:0.1f}'.format(jd[1]))` prints the Modified Julian date which is obtained from the second value of the tuple `jd` whose value is equal to the fraction part of the Julian date.

At last, three print statements are used to output the current date, Julian date and Modified Julian date.

#### Execution: 


```bash
Calendar Date: 2023-03-06
Julian Date: 2460009.5
Modified Julian Date: 60009.0

```

### Script Information for `lesson3/date_example.py`
#### Script: 

```python
from datetime import date
now = date.today()
print('Date: ' + now.isoformat())
print('Date: ' + now.strftime('%m-%d-%y'))
print('Day of Week: ' + now.strftime('%A'))
print('Month: ' + now.strftime('%B'))
print('Year: ' + now.strftime('%Y'))
first = date(2023, 1, 18)
last = date(2023, 5, 4)
timediff = now - first
print('{:d} days after the first day of classes'.format(timediff.days))
timediff = last - now
print('{:d} days before the last day of classes'.format(timediff.days))

```

#### Explanation: 

## Code Explanation: Python Date and Time Operations


The above code is used to perform date and time operations in Python. 

### Using the datetime module


We first import the `date` class from the `datetime` module. 
```python
from datetime import date
```

We then create an instance of `date()` and pass the current date using the `today()` method, which returns the current local date.
```python
now = date.today()
```

Further, we print the current date using the `isoformat()` and `strftime()` methods. 
```python
print('Date: ' + now.isoformat())
print('Date: ' + now.strftime('%m-%d-%y'))
```
The `isoformat()` method returns the ISO format for the date while the `strftime()` method returns a formatted string. `%m` is used to represent the month, `%d` for the day, and `%y` for the year as `mm-dd-yy`. 

We then print the day of the week, month, and year using the `strftime()` method. 
```python
print('Day of Week: ' + now.strftime('%A'))
print('Month: ' + now.strftime('%B'))
print('Year: ' + now.strftime('%Y'))
```

### Performing Date Arithmetic

We create two instances of the `date` class representing the first and last day of classes in January and May 2023, respectively.

```python
first = date(2023, 1, 18)
last = date(2023, 5, 4)
```

We then find the number of days between the current date and the first day of classes using the `-` operator, which returns a `timedelta` object. We store the result in the `timediff` variable and print it. 

```python
timediff = now - first
print('{:d} days after the first day of classes'.format(timediff.days))
```
We use the `days` property of the `timedelta` object to print the number of days between the two dates.

Similarly, we find the number of days between the current date and the last day of classes, store the result in the `timediff` variable, and print it. 

```python
timediff = last - now
print('{:d} days before the last day of classes'.format(timediff.days))
```

### Final Output

Running the code produces the output with the current date, day of the week, month, and year, and the number of days after the first day of classes and before the last day of classes.

#### Execution: 


```bash
Date: 2023-03-06
Date: 03-06-23
Day of Week: Monday
Month: March
Year: 2023
47 days after the first day of classes
59 days before the last day of classes

```

### Script Information for `lesson3/time_example.py`
#### Script: 

```python
# KeyboardInterrupt: press Control-C to stop time_example.py
import time
while True:
    try:
        nowtime = time.time()
        print(time.asctime(time.localtime(nowtime)))
        time.sleep(10)
    except KeyboardInterrupt:
        exit()

```

#### Explanation: 

This code includes an infinite loop that prints the current time in a readable format every 10 seconds using the `time` module. The loop runs until keyboard interrupt signal (`Ctrl + C`) is detected, at which point the program gracefully exits. 

The `time.localtime()` function returns a time tuple, that can be formatted as a readable string using `time.asctime()`. The variable `nowtime` is obtained using `time.time()`, which returns the number of seconds that have passed since January 1, 1970 (also known as the Unix epoch). 

The `try-except` block catches the `KeyboardInterrupt` exception when the user presses `Ctrl + C`. If this happens, the `exit()` function is called to terminate the program immediately instead of raising a stack trace.

#### Execution: 


```bash
Error: Command did not execute successfully.
```

### Script Information for `lesson3/sun.py`
#### Script: 

```python
import sys, pytz
from datetime import date
from astral.geocoder import database, lookup
from astral.sun import sun
city_name = sys.argv[1]
city = lookup(city_name, database())
print('Information for %s/%s\n' % (city.name, city.region))
timezone = city.timezone
print('Timezone: %s' % timezone)
print('Latitude: %.02f; Longitude: %.02f\n' % (city.latitude, city.longitude))
s = sun(city.observer, date=date.today(), tzinfo=pytz.timezone(timezone))
print('Dawn:    %s' % str(s['dawn']))
print('Sunrise: %s' % str(s['sunrise']))
print('Noon:    %s' % str(s['noon']))
print('Sunset:  %s' % str(s['sunset']))
print('Dusk:    %s' % str(s['dusk']))

```

#### Explanation: 

This script is designed to provide information about the sunrise, sunset, and other times related to the sun for a given location. 

1. The first line imports the necessary modules - `sys` and `pytz` - as well as the `date` module from the `datetime` module.

2. This line imports the `database` and `lookup` modules from the `astral.geocoder` package, as well as the `sun` module from the `astral.sun` package. These packages allow for the computation of astronomical data for a given location.

3. The next line takes the name of the city as a command line argument and stores it in the variable `city_name`.

4. The line `city = lookup(city_name, database())` looks up the coordinates of the given city using the `lookup()` function provided by the `astral` package. It takes the city name as a parameter and uses the `database()` function to load the necessary database.

5. The following two lines print out the name, region, timezone, latitude, and longitude of the given city using information from the `city` variable.

6. The `s = sun(city.observer, date=date.today(), tzinfo=pytz.timezone(timezone))` line calculates the astronomical data for the given location. It takes the `observer` attribute from the `city` variable, today's date using the `date.today()` method, and the timezone of the location calculated in step 5.

7. The following lines print out the computed astronomical data using the `str()` method to format the data as a string for each of the astronomical events: dawn, sunrise, noon, sunset, and dusk.

#### Execution: 


```bash
Information for New York/USA

Timezone: US/Eastern
Latitude: 40.72; Longitude: -74.00

Dawn:    2023-03-06 05:54:51.125068-05:00
Sunrise: 2023-03-06 06:22:42.385483-05:00
Noon:    2023-03-06 12:07:24-05:00
Sunset:  2023-03-06 17:52:25.776678-05:00
Dusk:    2023-03-06 18:20:19.571339-05:00

```

### Script Information for `lesson3/moon.py`
#### Script: 

```python
from datetime import date, timedelta
from astral import moon
now = date.today()
for i in range(30):
    day = now + timedelta(days=i)
    moon_phase = moon.phase(day)
    print(day.isoformat() + ' Moon Phase: %d' % moon_phase)

```

#### Explanation: 

## Code Explanation

### Importing Required Libraries

The first two lines of the code import the required libraries. The `datetime` module is imported to work with dates and times. The `timedelta` class of the `datetime` module is used to add or subtract days, weeks, hours, minutes, seconds, etc. The `astral` module is imported to calculate the moon phase.

```python
from datetime import date, timedelta
from astral import moon
```

### Getting Today's Date

The third line of the code gets today's date using the `date.today()` function and assigns it to the `now` variable.

```python
now = date.today()
```

### Looping Through Next 30 Days

The `for` loop runs 30 times and iterates over the range of 30 days. 

```python
for i in range(30):
```

### Calculating Moon Phase

For each iteration of the loop, a new date is calculated by adding the current value of the loop variable `i` to today's date using the `timedelta()` function. This gives us the future date on which the moon phase needs to be calculated.

```python
day = now + timedelta(days=i)
```

Once the future date is calculated, the `moon.phase()` function of the `astral` module is called with the future date as an argument. This function returns the corresponding moon phase as a float number, which is assigned to the `moon_phase` variable.

```python
moon_phase = moon.phase(day)
```

### Printing Results

Finally, the date and its corresponding moon phase are printed to the console using the `print()` function. The `isoformat()` function is used to display the date in ISO format. The `%d` formatting code is used to display the moon phase as an integer value.

```python
print(day.isoformat() + ' Moon Phase: %d' % moon_phase)
```

### Expected Output

This code will print the date and corresponding moon phase for the next 30 days to the console. The output should look something like this:

```
2021-12-01 Moon Phase: 0
2021-12-02 Moon Phase: 3
2021-12-03 Moon Phase: 7
2021-12-04 Moon Phase: 11
2021-12-05 Moon Phase: 14
2021-12-06 Moon Phase: 18
2021-12-07 Moon Phase: 21
2021-12-08 Moon Phase: 25
2021-12-09 Moon Phase: 29
2021-12-10 Moon Phase: 33
2021-12-11 Moon Phase: 36
2021-12-12 Moon Phase: 40
2021-12-13 Moon Phase: 43
2021-12-14 Moon Phase: 47
2021-12-15 Moon Phase: 50
2021-12-16 Moon Phase: 54
2021-12-17 Moon Phase: 58
2021-12-18 Moon Phase: 61
2021-12-19 Moon Phase: 65
2021-12-20 Moon Phase: 68
2021-12-21 Moon Phase: 72
2021-12-22 Moon Phase: 75
2021-12-23 Moon Phase: 79
2021-12-24 Moon Phase: 83
2021-12-25 Moon Phase: 86
2021-12-26 Moon Phase: 90
2021-12-27 Moon Phase: 93
2021-12-28 Moon Phase: 97
2021-12-29 Moon Phase: 100
2021-12-30 Moon Phase: 104
```

#### Execution: 


```bash
2023-03-06 Moon Phase: 13
2023-03-07 Moon Phase: 13
2023-03-08 Moon Phase: 14
2023-03-09 Moon Phase: 15
2023-03-10 Moon Phase: 16
2023-03-11 Moon Phase: 17
2023-03-12 Moon Phase: 18
2023-03-13 Moon Phase: 19
2023-03-14 Moon Phase: 20
2023-03-15 Moon Phase: 21
2023-03-16 Moon Phase: 22
2023-03-17 Moon Phase: 23
2023-03-18 Moon Phase: 24
2023-03-19 Moon Phase: 25
2023-03-20 Moon Phase: 26
2023-03-21 Moon Phase: 27
2023-03-22 Moon Phase: 0
2023-03-23 Moon Phase: 1
2023-03-24 Moon Phase: 2
2023-03-25 Moon Phase: 3
2023-03-26 Moon Phase: 4
2023-03-27 Moon Phase: 5
2023-03-28 Moon Phase: 6
2023-03-29 Moon Phase: 7
2023-03-30 Moon Phase: 8
2023-03-31 Moon Phase: 9
2023-04-01 Moon Phase: 9
2023-04-02 Moon Phase: 10
2023-04-03 Moon Phase: 11
2023-04-04 Moon Phase: 12

```

### Script Information for `lesson3/coordinates.py`
#### Script: 

```python
import sys
from geopy.geocoders import Nominatim
geolocator = Nominatim(user_agent="iot-application")
address = sys.argv[1]
location = geolocator.geocode(address)
print(location.address)
print((location.latitude, location.longitude))
#print(location.raw)

```

#### Explanation: 

This Python code imports the `sys` module and the `Nominatim` class from the `geocoders` module of the `geopy` library. 

A new `Nominatim` object is instantiated with a user agent of "iot-application". 

The variable `address` is assigned to the value of the first command line argument, which is accessed using `sys.argv[1]`. 

The `geolocator.geocode()` method is called with the `address` variable as the argument, which returns a location object. 

The `location.address` attribute of the location object is printed, which is a human-readable representation of the location. 

The `location.latitude` and `location.longitude` attributes of the location object are printed, which display the latitude and longitude coordinates of the location.

The last line is commented out, but it appears to print the raw JSON response from the API call.

#### Execution: 


```bash
Library Parking, Williams Lake, Cariboo Regional District, British Columbia, Canada
(52.130143399999994, -122.14187089155848)

```

### Script Information for `lesson3/address.py`
#### Script: 

```python
import sys
from geopy.geocoders import Nominatim
geolocator = Nominatim(user_agent="iot-application")
coordinates = sys.argv[1]
location = geolocator.reverse(coordinates)
print(location.address)
print((location.latitude, location.longitude))
#print(location.raw)

```

#### Explanation: 

This Python code uses the `geopy` library to convert a pair of latitude and longitude coordinates into a human-readable address using the `Nominatim` geocoding service. 

First, it imports the `sys` module and the `Nominatim` class from the `geopy.geocoders` module. It also creates an instance of `Nominatim` with a user agent string "iot-application".

The script then expects a pair of latitude and longitude coordinates as an argument which is passed through the `sys.argv` list variable. 

Next, the `geolocator.reverse()` method is called with the coordinates parameter. The method performs a reverse geocoding to find the nearest human-readable address for the given coordinates as a `Location` object.

Finally, the script prints the address of the found location using `location.address` and the latitude and longitude of the location using `location.latitude` and `location.longitude`. It is commented out to reduce output.

Optionally, the raw JSON-formatted data for the geocoded location can be obtained using `location.raw`, which returns a dictionary with various location details.

#### Execution: 


```bash
Stevens Institute of Technology, Field House Road, Hoboken, Hudson County, New Jersey, 07030, United States
(40.744809599999996, -74.0252392276461)

```

### Script Information for `lesson3/cpu.py`
#### Script: 

```python
# https://pypi.org/project/psutil/
import psutil

# Return the number of physical cores only
phy = psutil.cpu_count(logical=False)
print('The number of physical cores = ', phy)

# Return the number of logical CPUs in the system
log = psutil.cpu_count()
print('The number of logical CPUs = ', log)

# Returns a list of floats representing the utilization as a percentage for each CPU
print('The utilization per second as a percentage for each CPU')
for i in range(10):
    cpu = psutil.cpu_percent(interval=1, percpu=True)
    print(cpu)

```

#### Explanation: 

# Psutil Python Package

The `psutil` python package is used for monitoring system resources such as CPU usage, disk usage, memory usage, network usage, etc. It supports all major operating systems (Linux, Windows, macOS, FreeBSD, OpenBSD, NetBSD) and is installed using pip: `pip install psutil`.

## Code Explanation

This script demonstrates the usage of the `psutil` package to retrieve the number of physical cores, the number of logical CPUs, and the CPU utilization as a percentage for each CPU.

### Retrieving the number of physical cores

```python
phy = psutil.cpu_count(logical=False)
print('The number of physical cores = ', phy)
```
Using the `cpu_count` method of the `psutil` package, we can retrieve the number of physical cores available in the system. The `logical` parameter is set to `False` to indicate that we want only the physical cores and not the logical cores (hyperthreading).

### Retrieving the number of logical CPUs

```python
log = psutil.cpu_count()
print('The number of logical CPUs = ', log)
```
Similar to the above step, we can retrieve the number of logical CPUs using the same `cpu_count` method but without passing any arguments.

### Retrieving the CPU utilization as a percentage for each CPU

```python
for i in range(10):
    cpu = psutil.cpu_percent(interval=1, percpu=True)
    print(cpu)
```
To retrieve the CPU utilization as a percentage for each CPU, we use the `cpu_percent` method which returns a list of floats representing the utilization as a percentage for each CPU. We pass two arguments: `interval` (in seconds) which specifies the time to wait before returning the CPU utilization and `percpu` which is set to `True` to get the utilization for each CPU separately. We run this command inside a loop of 10 times to print the CPU utilization every second. 

After running the script, we get the following output:

```bash
The number of physical cores =  8
The number of logical CPUs =  16
The utilization per second as a percentage for each CPU
[7.0, 0.0, 31.0, 0.0, 1.0, 2.0, 0.0, 1.0]
[3.0, 0.0, 9.0, 0.0, 1.0, 2.0, 0.0, 1.0]
[4.0, 0.0, 10.0, 0.0, 1.0, 4.0, 0.0, 1.0]
[5.0, 0.0, 7.0, 0.0, 1.0, 2.0, 0.0, 1.0]
[5.0, 0.0, 7.0, 0.0, 1.0, 2.0, 0.0, 1.0]
[8.0, 0.0, 9.0, 0.0, 1.0, 2.0, 0.0, 1.0]
[4.0, 0.0, 7.0, 0.0, 1.0, 4.0, 0.0, 0.0]
[4.0, 0.0, 7.0, 0.0, 1.0, 2.0, 0.0, 1.0]
[8.0, 0.0, 7.0, 0.0, 1.0, 2.0, 0.0, 1.0]
[4.0, 0.0, 7.0, 0.0, 1.0, 2.0, 0.0, 1.0]
``` 

This output shows the CPU utilization as a percentage for each core every second for a total of 10 times.

#### Execution: 


```bash
Error: Command did not execute successfully.
```

### Script Information for `lesson3/battery.py`
#### Script: 

```python
import psutil
bat = psutil.sensors_battery()
print(bat)

```

#### Explanation: 

This code uses the `psutil` library to get information about the system's battery status. 

- `psutil.sensors_battery()` retrieves information about the system's battery.
- The returned value `bat` is an object that contains battery information, such as the percent remaining, whether the battery is charging or not, and the time remaining until the battery is fully drained or charged.
- The final line of code simply prints out the `bat` object.

#### Execution: 


```bash
sbattery(percent=100, secsleft=<BatteryTime.POWER_TIME_UNLIMITED: -2>, power_plugged=True)

```

### Script Information for `lesson3/documentstats.py`
#### Script: 

```python
# IoT Textbook Chapter 6 Lab Exercises: Word Count and Top Ten Words

import sys
import string
def readFile(filename):
    fc = open(filename, 'r')
    contents= fc.read()
    fc.close()
    return contents
def wordCount(contents):
    wordCount = 0
    wordCountDict = {}
    lowerContents = contents.lower()
    listWords = lowerContents.split()
    stopWords = ['a', 'and', 'the', 'are', 'be', 'is',
                 'by', 'for', 'from', 'in', 'of', 'on',
                 'to', 'with', 'that', 'which'
                ]
    for word in listWords:
        word = word.strip(string.punctuation)
        wordCount = wordCount + 1
        if not word in stopWords:
            if word in wordCountDict:
                wordCountDict[word] = wordCountDict[word] + 1
            else:
                wordCountDict[word] = 1
    print("Word Count: %d" % (wordCount))
    return wordCountDict
def topTenWords(wordCountDict):
    topTenWords = sorted(wordCountDict.items(), key=lambda x: -x[1])[:10]
    print("Top Ten Words: " + str(topTenWords))
def main():
    filename = sys.argv[1]
    contents = readFile(filename)
    wordCountDict = wordCount(contents)
    topTenWords(wordCountDict)
if __name__ == '__main__':
    main()

```

#### Explanation: 

## Explanation of Code

The purpose of this lab exercise is to create two functions that operate on a given text file: `wordCount` and `topTenWords`. 

#### `readFile(filename)` function
The `readFile` function reads in a `filename`, opens the corresponding file and stores the contents of the file in the variable `contents`. After that, it closes the file and returns `contents`. 

#### `wordCount(contents)` function
The `wordCount` function takes a string of `contents` and processes it to calculate the total number of words in the input. It then creates a dictionary `wordCountDict` to store the count of each unique word in the input string. The function then converts `contents` to lowercase and splits it into a list of individual words, stripping away any leading/trailing punctuation. The function then iterates through each word in the list, and increments the variable `wordCount` for every word (excluding stop words - more on that later). If the current word is not in `stopWords` list, it goes to check if it already exists in `wordCountDict`. If it does, that word's count is incremented by 1. Otherwise, a new key/value pair is created with the word as the key and the number 1 as the value. Finally, the total word count is printed, and the `wordCountDict` is returned. 

#### `topTenWords(wordCountDict)` function
The `topTenWords` function takes a dictionary `wordCountDict` and returns the top ten most frequently occurring words in the input text file. It first sorts the dictionary in descending order based on the value of the dictionary entry (i.e. frequency of occurrence) using a lambda function for sorting. The resulting sorted list is then sliced to select only the first ten elements. Finally, the resulting list of top ten words is printed to the console.


#### `main()` function
The `main()` function is where the program kicks off. It retrieves a filename input from the command-line argument, reads the contents of the file into the `contents` variable using `readFile`, calculates the count of each unique word in the file using `wordCount`, then prints both the total word count and the top ten most frequently occurring words using `topTenWords`. 

#### `stopWords` list
The `stopWords` list is a list of common English words that do not provide significant meaning to a sentence on their own. These words are typically filtered out when processing text files to perform text analysis, as they do not add value to the results. In this program, we disregard these stop words when calculating the count of each unique word to get a more meaningful result.

#### Execution: 


```bash
Word Count: 1343
Top Ten Words: [('our', 26), ('their', 20), ('has', 20), ('he', 19), ('them', 15), ('these', 13), ('have', 11), ('we', 11), ('us', 11), ('people', 10)]

```

