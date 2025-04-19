SELECT e.name as Employee
FROM employee e
INNER JOIN employee m ON m.id = e.managerID
WHERE e.salary > m.salary

