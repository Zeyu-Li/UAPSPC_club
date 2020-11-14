import math
x_bc, y_bc, s_bc, r_i, r_f = map(int, input().split()) 
x_p, y_p, s_p = map(int, input().split()) 

sbc_p = s_bc - s_p #relative velocity between blue zone and player

dp_rf = math.sqrt((x_p - x_bc)**2 + (y_p - y_bc)**2) - r_f  #distance between player and final circle
dbci_f = r_i - r_f  
dp_ri = dbci_f - dp_rf  

t_player = dp_rf/s_p
if sbc_p != 0:
    t_overtake = dp_ri / sbc_p
else:
    t_overtake = 0

if t_overtake < 0:
    if dbci_f > dp_rf:
        damage = 0
    else:
        damage = dp_rf / s_p
elif t_overtake > 0:
    if s_p > s_bc:
        damage = min(t_overtake, t_player)
    elif t_overtake < t_player:
        if s_bc > s_p:
            damage = (dp_rf - s_p*t_overtake) / s_p
    else:
        damage = 0
            
elif t_overtake == 0:
    if dp_rf <= dbci_f:
        damage = 0
    else:
        damage = t_player

print(f'{damage:.6f}') 