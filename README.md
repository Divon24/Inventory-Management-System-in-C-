# Inventory Management System in C++

## Project Overview

This is a terminal-based Inventory Management System written in C++ for managing shop inventory. It was created for a class project and provides basic features to display, buy, sell, add, and remove items, as well as manage balance. Users interact with a menu-driven system that supports item inventory management, sorting, and balance control.

## Features

- **Add Items**: Add new items with a name, type, and price to the shop inventory.
- **Remove Items**: Remove items from the shop by index.
- **Display Shop Inventory**: View all items currently available in the shop.
- **Display Personal Inventory**: View all items currently in the user's inventory.
- **Buy Items**: Purchase items from the shop if the user's balance is sufficient.
- **Sell Items**: Sell items from the user's inventory to increase balance.
- **Balance Management**: Add or remove balance.
- **Inventory Sorting**: Sort user inventory based on item price.

## Menu Options
The system includes the following menu-driven options:

Display Inventory: Shows items in the user's inventory.
Shop: Displays the shop's items and allows the user to buy items.
Sell Item: Allows the user to sell an item from their inventory.
Add New Item: Adds a new item to the shop inventory.
Remove Item: Removes an item from the shop inventory by index.
Order Inventory: Sorts the user inventory based on item price in ascending order.
Add Balance: Increases the user's balance.
Remove Balance: Sets the user's balance to zero.
Quit: Exits the program.
Code Structure
Item Class: Represents a single item with properties for name, type, and price.
Shop Class: Manages the collection of items available in the shop.
Main Menu Logic: Handles user input for navigating the menu and performing actions on the shop and inventory.
