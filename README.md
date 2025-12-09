# Electronic Voting Machine (EVM) Simulation

## Overview

The Electronic Voting Machine (EVM) Simulation is a microcontroller-based project designed to demonstrate a secure and efficient voting process for student elections. Developed using **C** and simulated on **Tinkercad**, this system addresses the need for fair and tamper-proof elections. It replaces traditional paper ballots with a digital interface that ensures accurate counting and restricts unauthorized access.

The system features a robust two-step verification process via the Serial Monitor. Access is strictly regulated: **Roll Numbers 1 to 69** are reserved for students to cast their votes, while **Roll Number 70** is reserved exclusively for the Administrator. The logic enforces a strict "One Person, One Vote" policy, preventing duplicate casting by the same student. This clear separation of privileges ensures the integrity and confidentiality of the election process.

# Tinkercad Circuit Diagram

<img width="1412" height="774" alt="Screenshot 2025-12-09 120829" src="https://github.com/user-attachments/assets/5fb41d70-0983-4e14-a2b4-2b7b4e2c74ca" />


## Features

* **Secure Authentication:** Logic-based login validating Student Roll Numbers (Range: 1–69) and matching Passwords.
* **Role-Based Access Control:** Distinguishes between **Voters** (Roll No: 1–69) and **Admin** (Roll No: 70) to prevent privilege misuse.
* **Duplicate Vote Prevention:** State-locking mechanism ensures a student can vote only once per session.
* **Admin Mode:** Exclusive access for Administrators (Credentials: 70/70) to reveal and monitor election results.
* **Interactive Simulation:** Uses Serial Monitor for prompts/feedback and Push Buttons for casting votes, visualized on an LCD screen.
* **Efficient C Logic:** Optimized code structure for instant feedback and state management.

## Try It Out

Experience the EVM Simulation right from your browser.
Click on the provided link to interact with the circuit and test the voting logic.

https://www.tinkercad.com/things/iMHbSRwqYc6-electronic-voting-machine/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard

## Run Simulation

### 📋 Prerequisites

* A web browser
* A **Tinkercad** account (free)
* Basic understanding of Arduino/C connections

### 1. Set Up the Circuit

If you are building this from scratch in Tinkercad:
1.  Create a new **Circuit**.
2.  Add an **Arduino Uno** (or compatible microcontroller).
3.  Set up the **LCD Screen** and **Push Buttons** (representing different Parties) as shown in the diagram above.
4.  Ensure the buttons are pulled down/up correctly as per the code logic.

### 2. Load the Code

1.  Open the **Code** panel in Tinkercad.
2.  Select **Text** mode (ensure it is set to C/C++).
3.  Copy the code from `main.c` (or the code file in this repo).
4.  Paste it into the editor.

### 3. Start the Election

1.  Click **Start Simulation**.
2.  Open the **Serial Monitor** (at the bottom of the code panel).
3.  Follow the prompts:
    * **To Vote:** Enter a valid Student Roll No (1–69) and matching Password.
    * **To View Results:** Enter Admin credentials (`70`, `70`).
