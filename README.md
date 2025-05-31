# 🐱🍔 Nyan Cat and Cheeseburger Game

A fun console-based grid game written in C++ where you play as a cheeseburger dodging Nyan Cats and collecting power-ups. Built using object-oriented programming and console rendering.

## Gameplay

- Control the Cheeseburger (`!`) and avoid falling Nyan Cats (`@`).
- Collect:
  - `S` (Shield) for temporary invincibility
  - `B` (Booster) to gain +10 score
  - `F` (Friend) to gain extra lives
- Score points and progress through levels as the game speeds up.

## 🕹 Controls

| Key | Action        |
|-----|---------------|
| `w` | Move up       |
| `s` | Move down     |
| `a` | Move left     |
| `d` | Move right    |
| `p` | Pause game    |
| `r` | Resume game   |
| `q` | Quit game     |

## Features

- Score saving to `scores.txt`
- Top 3 score tracking
- Dynamic difficulty (game speeds up with levels)
- ASCII grid display with colored elements
- Shield mechanic to absorb damage

## Project Structure

```bash
.
├── main.cpp         # Entry point and menu logic
├── header.h         # All class definitions and prototypes
├── scores.txt       # File to store top 3 scores
├── README.md        # This file
