# Curso: https://youtu.be/iYM2zFP3Zn0

# Fundamentals

- HTTP: Hyper Text Transfer Protocol

- Communication in server <-> client model

- Works with requests and responses

- Every single request is independent

- HTTPS: Hyper Text Transfer Procol Secura. Basically, encrypted HTTP

- We've got methods, like:  
    - Get Request: Retrieves data from the server  
    - Post Request: Submit data to the server  
    - Put Request: Update data already in the serverl  
    - etc...

- Each request and response have a header and a body, the body is basically the info (html's, for example). Usually a header will have the method, path, and protocol, as well as some other fields, like:  
    - General Fields  
        - Request URL  
        - Status Code  
        - Remote Addres  
        - etc...  
    - In Responses:  
        - Server  
        - Set-Cookie  
        - Content-Type  
        - Date  
        - etc..  
    - In Requests:  
        - Cookies  
        - Content-Type  
        - Authorization  
        - etc...

# HTTP Status Codes

- 1xx: Informational  
    - Request recieved / processing

- 2xx: Success  
    - Successfully Received

- 3xx: Redirect  
    - Further action must be taken

- 4xx: Client Error  
    - The request doesn't have the information it needs

- 5xx: Server Error  
    - Server failed to fulfil a request

- Important status examples:  
    - 200: OK  
    - 210: OK Created  
    - 301: Moved to new URL  
    - 304: Not Modified  
    - 400: Bad Request  
    - 401: Unauthorized  
    - 404: Not Found  
    - 500: Internal server error

- Already exist HTTP2, that is more efficient, faster and secure.

- If you go to a website, inspect, go to the "network" tab and refresh it, you can see a lot of archives that were transferred, as well as the http header, status, body, etc...

- The rest of the tutorial is basically him messing around with the http client Postman as if he were testing an API...