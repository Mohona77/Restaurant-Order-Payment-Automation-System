# Restaurant-Order-&-Payment-Automation-System
This project is a Restaurant Order & Payment Automation System that uses:

1. Singleton: To ensure a single instance of the Menu Manager, preventing duplication.

2. Factory: To dynamically create Order Objects (e.g., Dine-in, Takeaway, Delivery) for extensibility.

3. Observer: To notify customers and staff in real-time about order status updates.

4. Strategy: To implement flexible payment methods (e.g., Credit Card, Cash, Online) by encapsulating algorithms.

5. Command: To encapsulate order requests as objects, enabling features like undo/redo.

6. Facade: To simplify interactions with complex subsystems like Order Management and Payment Processing.

These patterns ensure the system is scalable, maintainable, and flexible, making it easy to adapt to future changes.
