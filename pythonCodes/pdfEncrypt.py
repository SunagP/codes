# from PyPDF2 import PdfFileReader,PdfFileWriter
#
# def secure(file,password):
#     parser = PdfFileWriter()
#     pdf = PdfFileReader()
#     for page in range(pdf.numPages):
#         parser.addPage(pdf.getPage(page))
#     parser.encrypt(password)
#     with open(f"encrypted_{file}","wb") as f:
#         parser.write(f)
#         f.close()
#     print(f"encrypted_{file} Created..")
#
# if __name__ == "__main__":
#  file = "1BM19IS162_LabOutput.pdf"
#  password = "sunag"
#  secure(file, password)
#
import PyPDF2
pdfFile = open(r'C:\Users\Asus\Desktop\my files\1612540138374.pdf', 'rb')
# Create reader and writer object
pdfReader = PyPDF2.PdfFileReader(pdfFile)
pdfWriter = PyPDF2.PdfFileWriter()
# Add all pages to writer (accepted answer results into blank pages)
for pageNum in range(pdfReader.numPages):
    pdfWriter.addPage(pdfReader.getPage(pageNum))
# Encrypt with your password
pdfWriter.encrypt('sunag')
# # Write it to an output file. (you can delete unencrypted version now)
resultPdf = open(r'C:\Users\Asus\Desktop\my files\output.pdf', 'wb')
pdfWriter.write(resultPdf)
print("successfully encrypted your file ...........")
resultPdf.close()
