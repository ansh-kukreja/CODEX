public class exp8b {
    public int calculateBill(int numOfRooms, int billPerRoom) {
        return numOfRooms * billPerRoom;
    }
    public float calculateBill(int numOfRooms, float billPerRoom) {
        return numOfRooms * billPerRoom;
    }
    public float calculateBill(float billPerBed, int numOfBeds) {
        return billPerBed * numOfBeds;
    }
    public double calculateBill(double billPerNight, int numOfNights) {
        return billPerNight * numOfNights;
    }
    public double calculateBill(double billPerNight, double discount, int numOfNights) {
        return (billPerNight * numOfNights) * (1 - discount);
    }

    public static void main(String[] args) {
        System.out.println("\n####### Gauraansh - 2210997081 - Exp8B ########\n");
    	exp8b hotel = new exp8b();
        int singleRoomBill = hotel.calculateBill(3, 100);
        float dormitoryBill = hotel.calculateBill(50.5f, 4);
        double specialRoomBill = hotel.calculateBill(140.94, 4);
        double guestRoomBill = hotel.calculateBill(200.40, 0.4, 2);

        System.out.println("Single Room Bill: $" + singleRoomBill);
        System.out.println("Dormitory Bill: $" + dormitoryBill);
        System.out.println("Special Room Bill: $" + specialRoomBill);
        System.out.println("Guest Room Bill: $" + guestRoomBill);
    }
}