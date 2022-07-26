class Cookie {
  private String name;
  private int amount;
  private String flavor;
  public Cookie(String name, int amount, String flavor) {
    this.name = name;
    this.amount = amount;
    this.flavor = flavor;
  }
  public boolean setName(String name) {
    try {
      this.name = name;
      return true;
    }
    catch (Exception e) {
      return false;
    }
  }
  public String getName() {
    return name;
  }
  public int getAmount() {
    return amount;
  }
  public String getFlavor() {
    return flavor;
  }
}
