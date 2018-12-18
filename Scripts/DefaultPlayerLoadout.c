class DefaultPlayerLoadout {

	private PlayerBase player;
	private EntityAI weapon;

	void DefaultPlayerLoadout(PlayerBase p){
		this.player = p;
		initLoadout();
	}

	void initLoadout(){
		player.RemoveAllItems();
		setBasicEquipment();
		setHandGun();
		setPrimaryGun();
		setVehicle();
	}

	void addMags(PlayerBase player, string mag_type, int count){
		if (count < 1)
			return;

		EntityAI mag;

		for (int i = 0; i < count; i++) {
			mag = player.GetInventory().CreateInInventory(mag_type);
		}
	}

	void setHandGun(){
		int oRandValue = Math.RandomIntInclusive(0,2);
		EntityAI pistol;

		switch(oRandValue.ToString())
		{
			case "0":
			pistol = player.GetInventory().CreateInInventory("FNX45");
			addMags(player, "Mag_FNX45_15Rnd", 2);
			break;

			case "1":
			pistol = player.GetInventory().CreateInInventory("CZ75");
			addMags(player, "Mag_CZ75_15Rnd", 2);
			break;

			case "2":
			pistol = player.GetInventory().CreateInInventory("makarovij70");
			addMags(player, "mag_ij70_8rnd", 2);
			break;
		}
		player.SetQuickBarEntityShortcut(pistol, 1, true);
	}

	void setPrimaryGun(){
		EntityAI primary = player.GetHumanInventory().CreateInInventory("M4A1");
		addMags(player, "Mag_STANAG_30Rnd", 3);
		primary.GetInventory().CreateAttachment("M4_OEBttstck");
		primary.GetInventory().CreateAttachment("M4_CarryHandleOptic");
		primary.GetInventory().CreateAttachment("M4_PlasticHndgrd");
		primary.GetInventory().CreateAttachment("weaponMuzzleM4");
		primary.GetInventory().CreateAttachment("weaponBayonet");

		player.LocalTakeEntityToHands(primary);
		player.SetQuickBarEntityShortcut(primary, 0, true);

	}

	void setVehicle(){
		EntityAI car;
        vector NewPosition;
        vector OldPosition;
        OldPosition = player.GetPosition();
        NewPosition[0] = OldPosition[0] + 2;
        NewPosition[1] = OldPosition[1] + 0.2;
        NewPosition[2] = OldPosition[2] + 2;
        car = EntityAI.Cast(GetGame().CreateObject( "OffroadHatchback", NewPosition, false, true, true ));
        car.GetInventory().CreateAttachment("HatchbackHood");
        car.GetInventory().CreateAttachment("HatchbackTrunk");
        car.GetInventory().CreateAttachment("HatchbackDoors_Driver");
        car.GetInventory().CreateAttachment("HatchbackDoors_CoDriver");
        car.GetInventory().CreateAttachment("HatchbackWheel");
        car.GetInventory().CreateAttachment("HatchbackWheel");
        car.GetInventory().CreateAttachment("HatchbackWheel");
        car.GetInventory().CreateAttachment("HatchbackWheel");
        car.GetInventory().CreateAttachment("HatchbackWheel"); //spare
        car.GetInventory().CreateAttachment("SparkPlug");
        car.GetInventory().CreateAttachment("EngineBelt");
        car.GetInventory().CreateAttachment("CarBattery");
        auto carfluids = Car.Cast( car );
        carfluids.Fill( CarFluid.FUEL, 1000 );
        carfluids.Fill( CarFluid.OIL, 1000 );
        carfluids.Fill( CarFluid.BRAKE, 1000 );
        carfluids.Fill( CarFluid.COOLANT, 1000 );
	}

	void setBasicEquipment()	{
		//
		TStringArray pants = {"Jeans_Black","Jeans_BlueDark","Jeans_Blue","Jeans_Brown","Jeans_Green","Jeans_Grey"};
		TStringArray shoes = {"AthleticShoes_Black","AthleticShoes_Brown","AthleticShoes_Grey","HikingBootsLow_Beige","HikingBootsLow_Black","HikingBootsLow_Grey","HikingBoots_Black","HikingJacket_Black"};
		TStringArray backpack = {"TortillaBag","HuntingBag","SmershBag","AssaultBag_Ttsko","AssaultBag_Black","AssaultBag_Green","CoyoteBag_Brown","CoyoteBag_Green","AliceBag_Green","AliceBag_Black","AliceBag_Camo"};
      	TStringArray vest = {"PoliceVest","HighCapacityVest_Olive","HighCapacityVest_Black"};
		TStringArray drink = {"SodaCan_Cola","SodaCan_Kvass","SodaCan_Pipsi","SodaCan_Spite"};
       	TStringArray food = {"Worm","SmallGuts","PowderedMilk","PeachesCan","Pear"};
		TStringArray tool = {"OrienteeringCompass","Knife","PurificationTablets","Matchbox"};
		TStringArray gloves = {"WorkingGloves_Yellow"};
		TStringArray faces = {"designerglasses"};
		//
		
		player.GetInventory().CreateInInventory(pants.GetRandomElement());
		player.GetInventory().CreateInInventory(shoes.GetRandomElement());
		player.GetInventory().CreateInInventory(backpack.GetRandomElement());
		player.GetInventory().CreateInInventory(vest.GetRandomElement());
		player.GetInventory().CreateInInventory(drink.GetRandomElement());
		player.GetInventory().CreateInInventory(food.GetRandomElement());
		player.GetInventory().CreateInInventory(tool.GetRandomElement());
		player.GetInventory().CreateInInventory(gloves.GetRandomElement());
		player.GetInventory().CreateInInventory(faces.GetRandomElement());
		player.GetInventory().CreateInInventory("CanOpener");
    	player.GetInventory().CreateInInventory("PersonalRadio");
    	player.GetInventory().CreateInInventory("Battery9V");
    	player.GetInventory().CreateInInventory("Battery9V");
		player.GetInventory().CreateInInventory("Canteen");
		player.GetInventory().CreateInInventory("OrienteeringCompass");
		ItemBase rags = ItemBase.Cast(player.GetInventory().CreateInInventory("Rag"));
		rags.SetQuantity(6);

		EntityAI primary;
		EntityAI axe = player.GetInventory().CreateInInventory("FirefighterAxe");
		player.SetQuickBarEntityShortcut(axe, 2, true);
	}
};