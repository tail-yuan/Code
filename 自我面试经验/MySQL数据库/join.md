#### join left Join rightJoin

"JOIN"、"LEFT JOIN" 和 "RIGHT JOIN" 是用于合并数据库表中数据的 SQL 查询操作。它们之间的主要区别在于它们如何匹配和返回数据。

1. **INNER JOIN（JOIN）**:
   - INNER JOIN 用于从两个表中**仅返回匹配的行**。
   - 如果两个表中的某行在连接条件下匹配，那么它将包含在结果集中。
   - 如果某行在一个表中有匹配，但在另一个表中没有匹配，那么该行将被忽略。

```sql
SELECT * FROM table1
INNER JOIN table2 ON table1.column = table2.column;
```

2. **LEFT JOIN**:
   - LEFT JOIN **返回左边表（第一个表）中的所有行**，以及与右边表（第二个表）中匹配的行。
   - 如果没有匹配的行，右边表中的列将包含 NULL 值。
   - 理解: 往left贴冷屁股,left肯定是都能打印的,那我没有和他匹配的就用NULL补上.

```sql
SELECT * FROM table1
LEFT JOIN table2 ON table1.column = table2.column;
```

3. **RIGHT JOIN**:
   - RIGHT JOIN 与 LEFT JOIN 类似，但它返回右边表中的所有行，以及与左边表中匹配的行。
   - 如果没有匹配的行，左边表中的列将包含 NULL 值。

```sql
SELECT * FROM table1
RIGHT JOIN table2 ON table1.column = table2.column;
```

总之，关键区别在于哪个表的所有行都包含在结果集中，以及如何处理没有匹配的行。

- INNER JOIN 仅包含匹配的行，
- LEFT JOIN 包含左边表的所有行，
- 而 RIGHT JOIN 包含右边表的所有行。

在选择使用哪种类型的连接时，取决于您的数据需求和表之间的关系。