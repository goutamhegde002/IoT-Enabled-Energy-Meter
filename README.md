# IoT-Enabled Energy Meter

## Description
Design a smart energy meter that tracks electricity usage and allows users to monitor and control their energy consumption remotely.

## Components
- Energy meter sensor
- Microcontroller
- Wi-Fi or GSM module
- Web dashboard or mobile app

## Project Code

### Arduino Code
The Arduino code reads energy usage from a sensor and sends the data to a server via HTTP.

**File:** `energy_meter.ino`

### Web Dashboard
A simple web dashboard to display the current energy usage.

**File:** `index.html`

### Server Setup
A basic Node.js server to handle incoming data from the energy meter and serve it to the web dashboard.

**File:** `server.js`

## How to Use

1. **Arduino:**
   - Connect the energy meter sensor to the Arduino.
   - Upload the Arduino code to the microcontroller.
   - Configure your Wi-Fi credentials and server URL in the code.

2. **Server:**
   - Install Node.js and Express.
   - Run the server using `node server.js`.

3. **Web Dashboard:**
   - Host `index.html` on a web server.
   - Ensure it points to the correct server URL to fetch energy data.

## Deployment
Deploy the server to a hosting platform or run it locally. Host the web dashboard on a web server or integrate it with your existing infrastructure.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.

## Contributing
Contributions are welcome! Please fork this repository and submit a pull request with your improvements.

## Notes
Ensure the server URL in the Arduino code and web dashboard matches the actual deployment URL. Adjust configurations as needed.
