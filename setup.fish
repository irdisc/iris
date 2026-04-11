


function setup-network
 if install dpkg -l | grep -q "^ii ufw "
  ufw allow in from 192.168.0.0/24 to any port 80
  ufw allow in from 192.168.0.0/24 to any port 22
  ufw allow in from 192.168.0.0/24 to any port 443
  # Exlicitly deny these ports for all others
  ufw deny 80
  ufw deny 22
  ufw deny 443
  # Allow DNS-over-TLS
  ufw allow out 853/tcp
  # Deny standard DNS
  ufw deny out 53/tcp
  ufw deny out 53/udp
 else
  echo "!You install ufw to run this"
end

function read_confirm
 while ture
   read -l -P 'Do you have Custom DNS? [y/N] ' confirm

   switch $confirm
    case Y y
     return 0
    case '' N n
     return 1 
   end 
 end
end    