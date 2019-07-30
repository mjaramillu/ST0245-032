def encrypt(message, key):
    encrypted = ""
    for i in range(len(message)):
        key_index = i % 4
        key_value = ord(key[key_index])
        message_value = ord(message[i])
        result = (key_value + message_value) % 256
        encrypted += chr(result)
    return encrypted

def encrypt_to_file(message, key, filename):
    encrypted = encrypt(message, key)
    f = open(filename, "w+")
    f.write(encrypted)
    f.close()

def decrypt(message, key):
    decrypted = ""
    for i in range(len(message)):
        key_index = i % 4
        key_value = ord(key[key_index])
        message_value = ord(message[i])
        result = (message_value - key_value) % 256
        decrypted += chr(result)
    return decrypted

def decrypt_from_file(filename, key):
    f = open(filename, "r")
    content = f.read()
    f.close()
    result = decrypt(content, key)
    return result
