Electronic Voting Machine (EVM) Simulation
Overview
The Electronic Voting Machine (EVM) Simulation is a microcontroller-based project designed to demonstrate a secure and efficient voting process for student elections. Developed using C and simulated on Tinkercad, this system addresses the need for fair and tamper-proof elections. It replaces traditional paper ballots with a digital interface that ensures accurate counting and restricts unauthorized access.

The system features a robust two-step verification process via the Serial Monitor. Access is strictly regulated: Roll Numbers 1 to 69 are reserved for students to cast their votes, while Roll Number 70 is reserved exclusively for the Administrator. The logic enforces a strict "One Person, One Vote" policy, preventing duplicate casting by the same student. This clear separation of privileges ensures the integrity and confidentiality of the election process.

Features
Secure Authentication: Logic-based login validating Student Roll Numbers (Range: 1–69) and matching Passwords.

Role-Based Access Control: Distinguishes between Voters (Roll No: 1–69) and Admin (Roll No: 70) to prevent privilege misuse.

Duplicate Vote Prevention: State-locking mechanism ensures a student can vote only once per session.

Admin Mode: Exclusive access for Administrators (Credentials: 70/70) to reveal and monitor election results.

Interactive Simulation: Uses Serial Monitor for prompts/feedback and Push Buttons for casting votes.

Efficient C Logic: Optimized code structure for instant feedback and state management.

Try It Out
Experience the EVM Simulation right from your browser. Click on the Tinkercad Link provided in the repository description to interact with the circuit and test the voting logic.

Run Simulation
📋 Prerequisites
A web browser

A Tinkercad account (free)

Basic understanding of Arduino/C connections

1. Set Up the Circuit
If you are building this from scratch in Tinkercad:

Create a new Circuit.

Add an Arduino Uno (or compatible microcontroller).

Connect Push Buttons to the digital pins (representing different Parties).

Ensure the buttons are pulled down/up correctly as per the code logic.

2. Load the Code
Open the Code panel in Tinkercad.

Select Text mode (ensure it is set to C/C++).

Copy the code from main.c (or the code file in this repo).

Paste it into the editor.

3. Start the Election
Click Start Simulation.

Open the Serial Monitor (at the bottom of the code panel).

Follow the prompts:

To Vote: Enter a valid Student Roll No (1–69) and matching Password.

To View Results: Enter Admin credentials (70, 70).

🤝 Contributing
We welcome contributions!

Fork and Create a Feature Branch
Bash

git checkout -b feature/your-feature-name
Stage, Commit and Push Changes
Bash

git add .
git commit -m "Add <description>"
git push origin feature/your-feature-name
After pushing your branch, create a Pull Request from your forked repo.
