from scapy.all import *

def main():
    while True:
        print_menu()
        option = input('Choose a menu option: ')
        if option == '1':
            print("Listening to all traffic to 127.0.0.1 for 1 minute ...")
            sniff(filter="host 127.0.0.1", prn=print_pkt, timeout=60)
        elif option == '2':
            print("End")
            break
        else:
            print(f"\nInvalid entry\n")

def print_pkt(packet):
    """ 
    Print Packet fields
    - Source IP
    - Destination IP
    - Protocol number
    - TTL
    - Length in bytes
    - Raw payload (if any)
    """
    print(f"Source IP: {packet[IP].src}")
    print(f"Destination IP: {packet[IP].dst}")
    print(f"Protocol number: {packet[IP].proto}")
    print(f"TTL: {packet[IP].ttl}")
    print(f"Length in bytes: {len(packet)}")
    if Raw in packet:
        print(f"Raw payload: {packet[Raw].load}")

def print_menu():
    """Prints the menu of options"""
    print("*******************Main Menu*******************")
    print('1. Listen to all traffic to 127.0.0.1 for 1 minute')
    print('2. Quit')
    print('***********************************************\n')

if __name__ == "__main__":
    main()