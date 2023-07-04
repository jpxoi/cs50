exit_code = False
while not exit_code:
    cc_number = int(input("Number: "))

    if cc_number > 0:
        digits = 0
        cc_number_count = cc_number
        while cc_number_count > 0:
            cc_number_count //= 10
            digits += 1

        # Check the Luhn algorithm
        if digits in (13, 15, 16):
            sum = 0
            digit = 0
            digit_count = 0
            cc_number_lunh = cc_number
            while cc_number_lunh > 0:
                digit = cc_number_lunh % 10

                # Check if the digit is in an even position
                if digit_count % 2 == 0:
                    sum += digit

                # Check if the digit is in an odd position
                else:
                    digit *= 2
                    if digit > 9:
                        digit -= 9
                    sum += digit
                digit_count += 1
                cc_number_lunh //= 10

            if sum % 10 == 0:
                # Get the first two digits
                first_two_digits = cc_number
                while first_two_digits > 100:
                    first_two_digits //= 10

                # Check if the first two digits are valid for AMEX
                if first_two_digits == 34 or first_two_digits == 37:
                    print("AMEX")
                    exit_code = True
                # Check if the first two digits are valid for MASTERCARD
                elif first_two_digits >= 51 and first_two_digits <= 55:
                    print("MASTERCARD")
                    exit_code = True
                # Check if the first two digits are valid for VISA
                elif first_two_digits // 10 == 4:
                    print("VISA")
                    exit_code = True
                # If the first two digits are not valid for any card type print INVALID and set exit_code to true
                else:
                    print("INVALID")
                    exit_code = True
            else:
                print("INVALID")
                exit_code = True
        else:
            print("INVALID")
            exit_code = True
    else:
        print("INVALID")
        exit_code = True