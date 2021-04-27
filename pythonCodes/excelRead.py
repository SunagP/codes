import xlrd

loc =(r"C:\Users\Asus\Desktop\my files\resume.xls")

wb = xlrd.open_workbook(loc)

sheet = wb.sheet_by_index(0)

print(sheet.row_values(0,1))

print(sheet.ncols)
print(sheet.nrows)
