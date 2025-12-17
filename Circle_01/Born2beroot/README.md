# Born2BeRoot 🐧🔐

**Born2BeRoot** is a system administration and virtualization project from the **42 Network Common Core**. The goal of this project is to introduce students to the **foundations of Linux system administration**, **security**, and **virtual machines**, without writing a single line of application code.

This project focuses on understanding how an operating system works from the inside: users, permissions, services, networking, firewalls, and security policies.

---

## 🎯 Project Goal

The main objective of Born2BeRoot is to **set up and secure a Linux server from scratch** inside a **virtual machine**, following strict rules and best practices.

You are asked to:
- Install and configure a Linux operating system
- Understand how a system boots and runs
- Secure the system according to defined policies
- Manage users, groups, and permissions
- Configure network services safely
- Document everything you do

This project is about **responsibility, rigor, and understanding**, not speed or coding.

---

## 🖥️ Virtualization

The entire project is done inside a **Virtual Machine (VM)** using tools such as:
- **VirtualBox** or **UTM**

Virtualization allows you to:
- Run a full operating system inside another one
- Experiment safely without risking your real machine
- Simulate real server environments

Understanding virtualization is a key concept in modern DevOps and system administration.

---

## 🐧 Operating System Choice

You must install **one of the following Linux distributions**:
- **Debian (stable)** ✅ *(most common choice)*
- **Rocky Linux**

During installation, you manually configure:
- Disk partitioning (LVM required)
- Hostname
- User accounts
- Passwords

This teaches how an OS is structured at a low level.

---

## 💽 Disk Partitioning & LVM

A critical part of Born2BeRoot is configuring **Logical Volume Management (LVM)**.

You learn:
- What partitions are
- Difference between physical volumes, volume groups, and logical volumes
- Why LVM is used in servers (flexibility, scalability)

Typical partitions include:
- `/` (root)
- `/home`
- `/var`
- `/srv`
- `/tmp`
- `/var/log`

This enforces **separation of concerns and security**.

---

## 👤 Users, Groups & Permissions

You must:
- Create a non-root user
- Configure **sudo** access securely
- Create and manage user groups

Concepts learned:
- Difference between `root` and normal users
- Linux permission model (`rwx`)
- Ownership (`user / group / others`)
- Principle of least privilege

This is fundamental to Linux security.

---

## 🔐 Password Policy & Security

The project enforces **strict password rules**, such as:
- Minimum length
- Character complexity
- Password expiration
- Protection against brute-force attacks

You configure:
- `login.defs`
- PAM modules

This introduces **real-world security practices** used in production systems.

---

## 🔥 Firewall Configuration

A firewall must be installed and configured:
- **UFW** (Debian)
- or **firewalld** (Rocky Linux)

You learn:
- What a firewall is
- How to open/close ports
- How to allow only necessary services

Only essential services (like SSH) should be accessible.

---

## 🌐 SSH (Secure Shell)

SSH is configured to:
- Run on a **non-default port**
- Disallow root login
- Allow only authorized users

Concepts learned:
- Remote server access
- Encryption
- Client/server communication

SSH is one of the most important tools in system administration.

---

## ⏱️ Cron & System Monitoring

You configure a **cron job** that periodically displays system information, such as:
- CPU usage
- RAM usage
- Disk usage
- Network connections
- Logged-in users

This introduces:
- Task scheduling
- System monitoring
- Automation

---

## 📊 System Information Script

A custom script is created to gather and display system stats.

This teaches:
- Shell scripting basics
- Interaction with system commands
- Parsing command output

Even without heavy scripting, this builds automation mindset.

---

## 📚 Documentation & Evaluation

A major part of Born2BeRoot is **being able to explain**:
- Every configuration choice
- Every installed service
- Every security decision

During evaluation, you must:
- Answer conceptual questions
- Demonstrate the running VM
- Prove understanding, not memorization

---

## 🧠 Concepts Learned

### System Administration
- Linux installation
- Boot process
- Service management

### Security
- Password policies
- User privilege separation
- Firewalls
- SSH hardening

### Networking
- Ports and services
- Local vs remote access

### Virtualization
- Virtual machines
- Resource isolation

### Automation
- Cron jobs
- Monitoring scripts

---

## 🚀 Why Born2BeRoot Matters

Born2BeRoot is often the **first project where students think like system administrators**, not programmers.

It builds:
- Discipline
- Attention to detail
- Responsibility
- Security awareness

These skills are essential for:
- Backend developers
- DevOps engineers
- System administrators
- Cybersecurity roles

---

## 📜 Disclaimer

This repository contains only:
- The official subject PDF
- This README for explanation purposes

No implementation files are provided.

This project is part of the **42 Network curriculum** and is intended for **educational use only**.

---

## 👤 Author

**Oussama Hassouni**  
42 Network – 1337 Coding School (Morocco)

---

🟢 *Born2BeRoot — Learning how systems really work, from the ground up.*