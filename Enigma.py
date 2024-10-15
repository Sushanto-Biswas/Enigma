def encrypt(text, shift):
    encrypted_text = []
    for ch in text:
        # Encrypt uppercase letters
        if 'A' <= ch <= 'Z':
            encrypted_text.append(chr((ord(ch) - ord('A') + shift) % 26 + ord('A')))
        # Encrypt lowercase letters
        elif 'a' <= ch <= 'z':
            encrypted_text.append(chr((ord(ch) - ord('a') + shift) % 26 + ord('a')))
        # Other characters remain unchanged
        else:
            encrypted_text.append(ch)
    return ''.join(encrypted_text)

def decrypt(text, shift):
    return encrypt(text, 26 - (shift % 26))  # Decryption is just encryption with a negative shift

def main():
    choice = int(input("Choose 1 to Encrypt or 2 to Decrypt: "))
    text = input("Enter text: ")

    shift = int(input("Enter shift value (1-25): "))
    if shift < 1 or shift > 25:
        print("Shift value must be between 1 and 25.")
        return

    if choice == 1:
        encrypted_text = encrypt(text, shift)
        print("Encrypted text:", encrypted_text)
    elif choice == 2:
        decrypted_text = decrypt(text, shift)
        print("Decrypted text:", decrypted_text)
    else:
        print("Invalid choice.")

if __name__ == "__main__":
    main()
