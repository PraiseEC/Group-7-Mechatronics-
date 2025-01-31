# Group-7-Mechatronics-

```markdown
# Voice-Controlled Home Automation System  
**Arduino-based system for controlling appliances and a servo motor using voice commands over serial communication.**  

---

## 📝 Description  
This project enables voice-controlled automation of lights, appliances, and a simulated door using an Arduino Uno, relay modules, and a servo motor. Commands are sent via a serial interface (e.g.Bluetooth terminal) to trigger actions like turning devices on/off or opening/closing a door.  

## 🚀 Features  
- Voice command control for 3 relays (appliances/lights) and 1 servo motor (door).  
- Real-time feedback via LED   
- Group commands (`all on`/`all off`) for bulk control.  
- Modular code structure for easy customization.  

## 🛠️ Hardware Requirements  
- Arduino Uno  
- 5V Relay Modules (x3)  
- SG90 Servo Motor  
- Jumper Wires & Breadboard  
- LED (for status feedback)  
- 1kΩ Resistor (for LED)  
- USB Cable (for Arduino)  
- Device for sending commands (PC/smartphone with serial terminal app)  

## 🔧 Installation  
1. **Software Setup**  
   - Install the [Arduino IDE](https://www.arduino.cc/en/software).  
   - Install the **Servo library** via `Sketch > Include Library > Manage Libraries`.  

2. **Upload Code**  
   - Clone this repository or copy the provided `.ino` file.  
   - Connect the Arduino to your computer.  
   - Upload the code to the Arduino.  

3. **Hardware Setup**  
   - Wire components as described in the [Wiring Guide](#wiring-guide).  

## 🎮 Usage  
1. Open the **Serial Monitor** (Tools > Serial Monitor, 9600 baud).  
2. Send voice commands (e.g., `lamp`, `fun`, `open door`, `all off`).  
3. Observe LED status and serial feedback for confirmation.  

### Supported Commands  
| Command       | Action                          |  
|---------------|---------------------------------|  
| `lamp`        | Turn Relay 1 (Lamp) ON          |  
| `offline one` | Turn Relay 1 OFF                |  
| `fun`         | Turn Relay 2 (Fan) ON           |  
| `offline 2`   | Turn Relay 2 OFF                |  
| `lights`      | Turn Relay 3 (Lights) ON        |  
| `offline 3`   | Turn Relay 3 OFF                |  
| `all on`      | Turn ALL relays ON              |  
| `all off`     | Turn ALL relays OFF             |  
| `open door`   | Rotate servo to 180° (open)     |  
| `close door`  | Rotate servo to 0° (close)      |  

## 🔌 Wiring Guide  
| Component     | Arduino Pin | Notes                   |  
|---------------|-------------|-------------------------|  
| Relay 1       | Pin 6       | Controls Lamp           |  
| Relay 2       | Pin 5       | Controls Fan           |  
| Relay 3       | Pin 4       | Controls Lights         |  
| Servo Motor   | Pin 9       | Door Lock Mechanism     |  
| LED           | Pin 13      | Status Indicator        |  

## 🌟 Future Enhancements  
- Integrate NLP for natural language processing.  
- Add wireless control via Bluetooth/Wi-Fi modules.  
- Develop a mobile app for remote access.  
- Implement noise cancellation for better command accuracy.  

## 🤝 Contributing  
Contributions are welcome!  
1. Fork this repository.  
2. Create a branch: `git checkout -b feature/your-idea`.  
3. Commit changes: `git commit -m 'Add your idea'`.  
4. Push to the branch: `git push origin feature/your-idea`.  
5. Open a pull request.  

## 📜 License  
This project is licensed under the **MIT License**. See [LICENSE](LICENSE) for details.  

---

**🔗 Acknowledgments**  
- Arduino Community for open-source libraries.  
- OpenAI for NLP inspiration.
- Bells University of Technology- New Horizons for the opportunity and resources used to create this project
-Mr Ayuba Muhammad for guidance and supervision over the project.
```
