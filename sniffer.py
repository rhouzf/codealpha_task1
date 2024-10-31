from scapy.all import sniff, wrpcap

def packet_callback(packet):
    print(packet.show())
    wrpcap('captured_packets.pcap', packet, append=True)

sniff(prn=packet_callback, count=3)
