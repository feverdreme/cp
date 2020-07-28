locate = str(st)
  ltion = []
  loc = 0
  while int(loc) < N:
      tel = locate.find("1",loc)
      if tel != -1:
          ltion.append(tel)
          loc = tel + 1
      else:
          loc = N

          #set for if even and if odd

          if tD != 1:
              D.append((tD - 1)/2.0)
          else:
              D.append(1.0)
