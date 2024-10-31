from scapy.all import sniff

def packet_callback(packet):
    print(packet.show())  # Affiche les détails du paquet sans enregistrer

# Capture trois paquets et applique la fonction d'affichage pour chacun
sniff(prn=packet_callback, count=3)
