# -*- coding: utf-8 -*-
# Author: José Rodolfo (jric2002)
class Producto:
  def __init__(self, name, empresa):
    self.name = name
    self.empresa = empresa
  def getName(self):
    return self.name
  def getEmpresa(self):
    return self.empresa
class Cookie(Producto):
  def __init__(self, name, empresa, idp):
    #super().__init__(name, empresa)
    Producto.__init__(self, name, empresa)
    self.idp = idp
  def getIdp(self):
    return self.idp
casino = Cookie("Casino", "Victoria", "12345")
print(casino.getEmpresa())
print(casino.getIdp())