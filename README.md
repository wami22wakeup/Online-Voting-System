# Online-Voting-System

A C++-based secure and modular voting system simulating the Indian election flow, complete with a user-friendly GUI built using Qt. The system supports EVM-style voting, NOTA, vote encryption, and result tallying — all stored using persistent CSV-based storage.

---

## 🚀 Features

- 🔐 **User Authentication**  
  Voters are verified using unique Voter IDs to prevent duplicate voting.
  
- 🖥️ **Graphical User Interface (GUI)**  
  Built using Qt to provide an intuitive experience with buttons for each candidate, EVM-like interaction, and visual feedback.

- 🔐 **Vote Encryption**  
  XOR-based reversible encryption ensures that vote data is stored in an obfuscated manner.

- 📄 **CSV-based Persistent Storage**  
  Votes are stored in encrypted form along with timestamps for traceability.

- 🔍 **Real-Time Vote Tallying**  
  Admin users can view live results using password-based access.

- ✅ **NOTA Support**  
  "None of the Above" option is included as a valid vote choice.


## 🛠️ Tech Stack

- **Language**: C++
- **GUI**: Qt
- **File Handling**: fstream
- **Encryption**: XOR-based (custom)
- **Data Storage**: CSV

---

## 🔧 How It Works

1. **Voter ID Verification**  
   Checks if the voter has already voted using a tracking mechanism (`voted.csv` or similar).

2. **Vote Casting**  
   Voter selects a candidate via GUI buttons. Confirmation is required to proceed.

3. **Encryption & Storage**  
   The vote data (Voter ID, Candidate, Timestamp) is encrypted and stored in `votes.csv`.

4. **Admin Access**  
   Admins can log in using a password to view decrypted and aggregated voting results.

---

## 🧠 Future Plans

- 🧑‍💼 **Candidate Registration Dashboard**  
  Allow future election candidates to register and manage profiles via an admin dashboard.

- 🧠 **Face Authentication for Voters**  
  Replace manual Voter ID entry with AI-based facial recognition to enhance security.

- 🧾 **Blockchain-Style Ledger**  
  Record votes in an immutable chain to prevent tampering and enhance auditability.

- 🌐 **Networked Version**  
  Transition from offline CSV-based logic to a client-server architecture using sockets or HTTP.

---

## 🧪 To-Do List

- [ ] Add GUI for admin dashboard
- [ ] Connect face recognition module (OpenCV + Dlib or similar)
- [ ] Improve encryption using AES or RSA
- [ ] Unit testing with mock voter data
- [ ] Refactor into class-based structure



