CREATE TABLE receipts (customer_id int, customer_name VARCHAR(50), purchase_date DATE, production VARCHAR(50));

INSERT INTO receipts
SELECT cu.id AS customer_id,
	   concat(cu.first_name, ' ', cu.last_name) AS customer_name,
	   tr.purchase_date,
	   concat(ca.brand, ' ', ca.model, ' ', ca.model_year) AS production
FROM customers cu
JOIN transactions tr ON cu.id = tr.buyer_id
JOIN cars ca ON tr.production_id = ca.id