import sqlite3

# insert / delete / update
con = sqlite3.connect("tutorial.db")
cur = con.cursor()
cur.execute("SQL statement")
con.commit()  # commit transaction

# query
res = cur.execute("SELECT")
# res.fetchall()
for row in res:
    print(row)
