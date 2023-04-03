#pip (ou pip3.xx) install secure-smtplib - pour le smtp

import smtplib
import os
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email.mime.text import MIMEText
from email.utils import COMMASPACE
from email import encoders
from email.mime.application import MIMEApplication

# Read SMTP password from file
with open("credentials.txt", "r") as f:
	smtp_password = f.readline().strip()

# SMTP connection details
smtp_server = "smtp-mail.outlook.com"
smtp_port = 25
smtp_username = "Aprilsfooltest@outlook.com"

# Email details
# from_email = "addf6f46-a7fb-46ce-a5c5-2a21559aa298@mailslurp.mx"
from_email = "Aprilsfooltest@outlook.com"
to_email = "Aprilsfooltest@outlook.com"
subject = "Test email with attachment #15"
body = "This is a test email with an attachment."

# Create the email with attachment
msg = MIMEMultipart()
msg["From"] = from_email
msg["To"] = COMMASPACE.join([to_email])
msg["Subject"] = subject

# Add email body
msg.attach(MIMEText(body, "plain"))

# Make the attachment
attachment_path = "installation.txt"
filename = os.path.basename(attachment_path)
with open(attachment_path, "rb") as attachment:
	part = MIMEApplication(attachment.read(), _subtype='txt')


# Add header as key/value pair to attachment part
part.add_header('Content-Disposition', 'part', filename=filename)

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
