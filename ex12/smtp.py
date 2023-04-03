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
# from_email = "addf6f46-a7fb-46ce-a5c5-2a21559aa298@mailslurp.mx"
from_email = "c1d61330-8ac1-401f-a23e-cdf970ce6747@mailslurp.com"
to_email = "c1d61330-8ac1-401f-a23e-cdf970ce6747@mailslurp.com"
subject = "Test email with attachment #10"
body = "This is a test email with an attachment."

# Create the email with attachment
msg = MIMEMultipart("html")
msg["From"] = from_email
msg["To"] = COMMASPACE.join([to_email])
msg["Subject"] = subject

# Add email body
msg.attach(MIMEText(body, "plain"))


attachment_path = "installation.txt"
filename = os.path.basename(attachment_path)
with open(attachment_path, "rb") as attachment:
    part = MIMEBase("application", "octet-stream")
    part.set_payload(attachment.read())

# Encode the attachment
encoders.encode_base64(part)

# Add header as key/value pair to attachment part
part.add_header("Content-Disposition", "attachment; filename= %s" %filename)

# Add attachment to message and convert message to string
msg.attach(part)
text = msg.as_string()

# Send the email
try:
    with smtplib.SMTP(smtp_server, smtp_port) as server:
        server.starttls()
        server.login(smtp_username, smtp_password)
        server.sendmail(from_email, [to_email], text)
        print("Email sent successfully.")
except Exception as e:
    print(f"An error occurred while sending the email: {e}")
