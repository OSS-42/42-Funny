#pip (ou pip3.xx) install secure-smtplib - pour le smtp

import smtplib
import os
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email.mime.text import MIMEText
from email.utils import COMMASPACE
from email import encoders

# Read SMTP password from file
with open("credentials.txt", "r") as f:
    smtp_password = f.readline().strip()

# SMTP connection details
smtp_server = "mailslurp.mx"
smtp_port = 2587
smtp_username = "hHQx4KJgaURh4szXPg8cbqn0sr7nLnyb"

# Email details
from_email = "addf6f46-a7fb-46ce-a5c5-2a21559aa298@mailslurp.mx"
to_email = "c1d61330-8ac1-401f-a23e-cdf970ce6747@mailslurp.com"
subject = "Test email with attachment #4"
body = "This is a test email with an attachment."

# Create the email with attachment
msg = MIMEMultipart()
msg["From"] = from_email
msg["To"] = COMMASPACE.join([to_email])
msg["Subject"] = subject

# Add email body
msg.attach(MIMEText(body, "plain"))

# # Attach the file
# attachment_path = "../ex15/42.png"
# attachment_name = os.path.basename(attachment_path)
# with open(attachment_path, "rb") as f:
#     part = MIMEBase("application", "octet-stream")
#     part.set_payload(f.read())
#     encoders.encode_base64(part)
#     part.add_header("Content-Disposition", f"attachment; filename={attachment_name}")
#     msg.attach(part)

# # Attach the file
# from email.mime.application import MIMEApplication

# attachment_path = "42.png"
# attachment_name = os.path.basename(attachment_path)
# with open(attachment_path, "rb") as f:
#     part = MIMEApplication(f.read(), Name=attachment_name)
#     part["Content-Disposition"] = f'attachment; filename="{attachment_name}"'
#     msg.attach(part)

# Attach the file
from email.mime.image import MIMEImage

attachment_path = "42.png"
attachment_name = os.path.basename(attachment_path)
with open(attachment_path, "rb") as f:
    img_data = f.read()
    part = MIMEImage(img_data, name=attachment_name)
    part["Content-Disposition"] = f'attachment; filename="{attachment_name}"'
    msg.attach(part)

# Send the email
try:
    with smtplib.SMTP(smtp_server, smtp_port) as server:
        server.starttls()
        server.login(smtp_username, smtp_password)
        server.sendmail(from_email, [to_email], msg.as_string())
        print("Email sent successfully.")
except Exception as e:
    print(f"An error occurred while sending the email: {e}")
