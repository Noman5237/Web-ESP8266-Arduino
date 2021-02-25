GUI interface for Arduino Control in the Web though ESP8266 Core without NodeMCU

Here are two PWM pins for controlling pin 10 and 11
And also two fully digital pins for controlling pin 12 and 13

We can create all sorts of fancy UI but this is the basic

> Step 1: Paste the IP address obtained from successfully completing the physical connection in .env file

> Step 2: Install the necessary npm modules using 'npm i'

> Step 3: Then start the server using 'npm start'

> After that you are happy to play with this thing

So to summarize web gui sends a GET request
`http://192.168.0.104/data?mode=a&pin=10&data=50`

to server setup in ESP8266 with arguments and then the server program at ESP8266 parses the information
And communicates the necessary data to Arduino using serial ports
`<a10,50>`

After that arduino receives the transmissions breaks it down and executes it.

<h2>Create ISSUE if you have any trouble</h2>
