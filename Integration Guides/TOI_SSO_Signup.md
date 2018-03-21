## **TOI_SSO** or **OTP**

In `TOI_SSO` authentication type user’s phone number will be validated from the Haptik Backend via a client API for additional security before Haptik account and wallet creation.

The following parameters are required while signing up with **TOI_SSO** authType on top of what is required for **BASIC** authType:

- *Mandatory*: OTP Verified Mobile Number
- *Mandatory*: Token/TicketId for OTP verification (for 3-way handshake, creation of Wallet)
- *Optional*: Resident City
