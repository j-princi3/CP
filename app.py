# import camelot

# # 1) Read tables from the PDF
# tables = camelot.read_pdf("my_report.pdf", pages="1", flavor="lattice")  # or stream if needed

# # 2) Check how many tables were found
# print(f"Found {len(tables)} tables")

# # 3) Convert the first table to a pandas DataFrame
# df = tables[0].df
# print(df)

# # 4) Export the first table directly to Excel
# tables[0].to_excel("extracted_table.xlsx")
import pandas as pd

# 1. Read the raw extracted text file
with open('extracted_table.csv', 'r', encoding='utf-8') as file:
    data = file.read()

# 2. Read into pandas DataFrame
from io import StringIO
df = pd.read_csv(StringIO(data), header=None)

# 3. (Optional) Find where the actual table starts (skip header text)
start_idx = 0
df_table = df.iloc[start_idx:].reset_index(drop=True)

# 4. Fix first row as column headers
df_table.columns = df_table.iloc[0]  # set first row as header
df_table = df_table.drop(0).reset_index(drop=True)

# 5. Save the clean table to Excel
df_table.to_excel("final_table.xlsx", index=False)

print("✅ Excel file 'final_table.xlsx' created successfully!")
