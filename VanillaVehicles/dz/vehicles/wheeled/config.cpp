class CfgPatches
{
  class VanillaVehicles_Vehicles_Wheeled
  {
    units[]={};
    weapons[]={};
    requiredVersion=0.1;
    requiredAddons[]={ "DZ_Data", "DZ_Vehicles_Wheeled" };
  };
};

class CfgVehicles
{
  class Inventory_Base;
  class CarWheel: Inventory_Base
  {
    //itemSize[]={6,6};
    itemSize[]={5,5};
    //weight=12000;
    weight=10000;
    repairableWithKits[]={6};
    repairCosts[]={25};
    lockType=3;
    class DamageSystem
    {
      class GlobalHealth
      {
        class Health
        {
          //hitpoints=200;
          hitpoints=250;
        };
      };
    };
  };
  class CarDoor: Inventory_Base
  {
		itemSize[]={10,10};
		weight=20000;
    repairableWithKits[]={10};
    repairCosts[]={50};
    lockType=2;
    class DamageSystem
    {
      class GlobalHealth
      {
        class Health
        {
          hitpoints=500;
        };
      };
      class DamageZones
      {
        class Window
        {
          class Health
          {
            //hitpoints=70;
            hitpoints=100;
            transferToGlobalCoef=0;
          };
        };
        class Doors
        {
          class Health
          {
            hitpoints=500;
            transferToGlobalCoef=1;
          };
        };
      };
    };
  };
  class Car;
  class CarScript: Car
  {
    fuelCapacity=50;
    fuelConsumption=10;
    batterySlot="CarBattery";
    class NoiseCarHorn
    {
      strength=30;
      type="sound";
    };
  };

  // ###################################################################################################################
  // OffroadHatchback - ADA 5MT AWD
  // ###################################################################################################################
  class HatchbackWheel: CarWheel
  {
    itemSize[]={6,6};
    weight=16000;
    repairableWithKits[]={6};
    repairCosts[]={35};
    //radiusByDamage[]={0.0, 0.36199999, 0.30000001, 0.30000001, 0.99980003, 0.25, 0.99989998, 0.2};
    radiusByDamage[]={0.0, 0.362, 0.3, 0.3, 0.9998, 0.25, 0.9999, 0.2};
    //radius=0.34999999;
    radius=0.35;
    //width=0.17;
    width=0.18;
    //tyreOffroadResistance=0.75;
    tyreOffroadResistance=1.25;
    //tyreGrip=0.80000001;
    tyreGrip=1.6;
    //tyreRollResistance=0.015;
    tyreRollResistance=0.03;
  };
  class OffroadHatchback: CarScript
  {
    fuelCapacity=42;
    fuelConsumption=11;
    class SimulationModule
    {
      class Steering
      {
        //maxSteeringAngle=30;
        maxSteeringAngle=35;
        increaseSpeed[]={0, 40, 30, 20, 100, 5};
        decreaseSpeed[]={0, 80, 60, 40, 90, 20};
        centeringSpeed[]={0, 0, 15, 25, 60, 40, 100, 60};
      };
      class Throttle
      {
        //reactionTime=0.89999998;
        reactionTime=0.45;
        //defaultThrust=0.85000002;
        defaultThrust=0.85;
        //gentleThrust=0.69999999;
        gentleThrust=0.7;
        //turboCoef=4;
        turboCoef=2;
        gentleCoef=0.75;
      };
      class Brake
      {
        //pressureBySpeed[]={0, 0.75, 10, 0.64999998, 20, 0.5, 40, 0.40000001, 60, 0.43000001, 80, 0.44999999, 100, 0.5, 120, 0.64999998};
        pressureBySpeed[]={0, 0.75, 10, 0.65, 20, 0.5, 40, 0.4, 60, 0.43, 80, 0.45, 100, 0.5, 120, 0.65};
        //gentleCoef=0.64999998;
        gentleCoef=0.65;
        minPressure=0.2;
        //reactionTime=0.30000001;
        reactionTime=0.3;
        driverless=0.1;
      };
      drive="DRIVE_AWD";
      class Engine
      {
        //torqueCurve[]={650, 0, 750, 40, 1400, 80, 3400, 114, 5400, 95, 8000, 0};
        torqueCurve[]={600, 0, 1200, 70, 2200, 115, 3500, 100, 5000, 80, 8000, 0};
        inertia=0.11;
        frictionTorque=100;
        rollingFriction=0.5;
        viscousFriction=0.5;
        rpmIdle=800;
        rpmMin=900;
        rpmClutch=1400;
        rpmRedline=6000;
      };
      class Clutch
      {
        maxTorqueTransfer=240;
        //uncoupleTime=0.30000001;
        uncoupleTime=0.3;
        //coupleTime=0.44999999;
        coupleTime=0.45;
      };
      class Gearbox
      {
        type="GEARBOX_MANUAL";
        reverse=3.526;
        //ratios[]={3.6670001,2.0999999,1.3609999,1};
        ratios[]={3.667,2.650,1.915,1.384,1.000};
      };
      class CentralDifferential
      {
        ratio=1.5;
        type="DIFFERENTIAL_LOCKED";
      };
      class Axles
      {
        class Front
        {
          maxBrakeTorque=1900;
          maxHandbrakeTorque=5000;
          wheelHubMass=5;
          wheelHubRadius=0.15000001;
          class Differential
          {
            ratio=4.0999999;
            type="DIFFERENTIAL_OPEN";
          };
          class Suspension
          {
            stiffness=40000;
            //compression=2100;
            compression=3675;
            //damping=7500;
            damping=16875;
            travelMaxUp=0.088200003;
            travelMaxDown=0.083300002;
          };
        };
        class Rear
        {
          maxBrakeTorque=1560;
          maxHandbrakeTorque=5000;
          wheelHubMass=5;
          wheelHubRadius=0.15000001;
          class Differential
          {
            ratio=4.0999999;
            type="DIFFERENTIAL_OPEN";
          };
          class Suspension
          {
            stiffness=40000;
            //compression=2200;
            compression=3850;
            //damping=7600;
            damping=17100;
            travelMaxUp=0.1587;
            travelMaxDown=0.1059;
          };
        };
      };
    };
    class Cargo
    {
      //itemsCargoSize[]={10, 30};
      itemsCargoSize[]={10, 40};
      allowOwnedCargoManipulation=1;
      openable=0;
    };
    class DamageSystem
    {
      class GlobalHealth
      {
        class Health
        {
          hitpoints=1000;
        };
      };
      class DamageZones
      {
        class Chassis
        {
          class Health
          {
            hitpoints=3000;
            transferToGlobalCoef=0;
          };
        };
        class Front
        {
          class Health
          {
            hitpoints=1200;
            transferToGlobalCoef=0;
          };
        };
        class Reflector_1_1
        {
          class Health
          {
            hitpoints=10;
            transferToGlobalCoef=0;
          };
        };
        class Reflector_2_1;
        class Back
        {
          class Health
          {
            hitpoints=1500;
            transferToGlobalCoef=0;
          };
        };
        class Roof
        {
          class Health
          {
            hitpoints=700;
            transferToGlobalCoef=0;
          };
        };
        class Fender_1_1
        {
          class Health
          {
            hitpoints=1200;
            transferToGlobalCoef=0;
          };
        };
        class WindowFront
        {
          class Health
          {
            hitpoints=120;
            transferToGlobalCoef=0;
          };
        };
        class WindowLR
        {
          class Health
          {
            hitpoints=150;
            transferToGlobalCoef=0;
          };
        };
        class Engine
        {
          fatalInjuryCoef=0.001;
          class Health
          {
            hitpoints=1000;
            transferToGlobalCoef=1;
          };
        };
        class FuelTank
        {
          class Health
          {
            hitpoints=500;
            transferToGlobalCoef=0;
          };
        };
      };
    };
  };

  // ###################################################################################################################
  // Hatchback_02 - GUNTER 4AT FWD
  // ###################################################################################################################
  class Hatchback_02_Wheel: CarWheel
  {
    itemSize[]={5,5};
    weight=10000;
    repairableWithKits[]={6};
    repairCosts[]={20};
    //radiusByDamage[]={0, 0.34, 0.30000001, 0.30000001, 0.99980003, 0.25, 0.99989998, 0.2};
    radiusByDamage[]={0.0, 0.34, 0.3, 0.3, 0.9998, 0.25, 0.9999, 0.2};
    //radius=0.30399999;
    radius=0.305;
    //width=0.15000001;
    width=0.16;
    //tyreOffroadResistance=0.2;
    tyreOffroadResistance=0.4;
    //tyreGrip=0.88999999;
    tyreGrip=1.8;
    //tyreRollResistance=0.0099999998;
    tyreRollResistance=0.02;
  };
  class Hatchback_02 : CarScript
  {
    fuelCapacity=55;
    fuelConsumption=6.5;
    class SimulationModule
    {
      class Steering
      {
        maxSteeringAngle=35;
        increaseSpeed[]={0, 50, 60, 30, 100, 15};
        decreaseSpeed[]={0, 90, 60, 45, 100, 20};
        centeringSpeed[]={0, 0, 15, 27, 60, 45, 100, 63};
      };
      class Throttle
      {
        //reactionTime=0.85000002;
        reactionTime=0.45;
        //defaultThrust=0.69999999;
        defaultThrust=0.7;
        //gentleThrust=0.40000001;
        gentleThrust=0.4;
        //turboCoef=2.2;
        turboCoef=0.8;
        gentleCoef=0.5;
      };
      class Brake
      {
        //pressureBySpeed[]={0, 0.5, 10, 0.40000001, 20, 0.30000001, 40, 0.28, 60, 0.30000001, 80, 0.38, 100, 0.41999999, 120, 0.47999999, 150, 0.60000002};
        pressureBySpeed[]={0, 0.5, 10, 0.4, 20, 0.3, 40, 0.28, 60, 0.3, 80, 0.38, 100, 0.42, 120, 0.48, 150, 0.6};
        //gentleCoef=0.69999999;
        gentleCoef=0.7;
        minPressure=0.2;
        reactionTime=0.2;
        driverless=0.1;
      };
      class Aerodynamics
      {
        //frontalArea=2.1500001;
        frontalArea=2.15;
        //dragCoefficient=0.51999998;
        dragCoefficient=0.52;
        //downforceCoefficient=0.0099999998;
        downforceCoefficient=0.01;
        //downforceOffset[]={0, 0.80000001, -0.69999999};
        downforceOffset[]={0, 0.8, -0.7};
      };
      drive="DRIVE_FWD";
      class Engine
      {
        //torqueCurve[]={850, 0, 1150, 90, 2000, 130, 4400, 186, 5800, 165, 7500, 0};
        torqueCurve[]={650, 0, 1200, 105, 2200, 165, 3600, 190, 4800, 145, 5500, 0};

        //inertia=0.20999999;
        inertia=0.21;
        frictionTorque=150;
        rollingFriction=0.2;
        viscousFriction=0.5;
        //rpmIdle=1250;
        rpmIdle=650;
        //rpmMin=1500;
        rpmMin=800;
        rpmClutch=1800;
        rpmRedline=5000;
      };
      class Clutch
      {
        maxTorqueTransfer=360;
        uncoupleTime=0.25;
        //coupleTime=0.34999999;
        coupleTime=0.35;
      };
      class Gearbox
      {
        // type="GEARBOX_MANUAL";
        type="GEARBOX_AUTOMATIC";
        reverse=3.1670001;
        //ratios[]={3.4549999, 2.118, 1.444, 1.1289999, 0.912};
        ratios[]={3.455, 2.216, 1.422, 0.912};
      };
      class Axles
      {
        class Front
        {
          maxBrakeTorque=2060;
          wheelHubMass=5;
          wheelHubRadius=0.125;
          class Differential
          {
            ratio=3.6670001;
            type="DIFFERENTIAL_OPEN";
          };
          class Suspension
          {
            stiffness=27000;
            //compression=2000;
            compression=3500;
            //damping=7500;
            damping=16875;
            travelMaxUp=0.16;
            travelMaxDown=0.16;
          };
        };
        class Rear
        {
          maxBrakeTorque=1500;
          maxHandbrakeTorque=4000;
          wheelHubMass=5;
          wheelHubRadius=0.125;
          class Suspension
          {
            stiffness=27500;
            //compression=2100;
            compression=3675;
            //damping=8000;
            damping=18000;
            travelMaxUp=0.16;
            travelMaxDown=0.16;
          };
        };
      };
    };
    class Cargo
    {
      itemsCargoSize[]={10, 30};
      allowOwnedCargoManipulation=1;
      openable=0;
    };
    class DamageSystem
    {
      class GlobalHealth
      {
        class Health
        {
          hitpoints=1000;
        };
      };
      class DamageZones
      {
        class Chassis
        {
          class Health
          {
            hitpoints=3000;
            transferToGlobalCoef=0;
          };
        };
        class Front
        {
          class Health
          {
            hitpoints=700;
            transferToGlobalCoef=0;
          };
        };
        class Reflector_1_1
        {
          class Health
          {
            hitpoints=20;
            transferToGlobalCoef=0;
          };
        };
        class Back
        {
          class Health
          {
            hitpoints=500;
            transferToGlobalCoef=0;
          };
        };
        class Roof
        {
          class Health
          {
            hitpoints=400;
            transferToGlobalCoef=0;
          };
        };
        class Fender_1_1
        {
          class Health
          {
            hitpoints=700;
            transferToGlobalCoef=0;
          };
        };
        class WindowFront
        {
          class Health
          {
            hitpoints=100;
            transferToGlobalCoef=0;
          };
        };
        class Engine
        {
          fatalInjuryCoef=0.001;
          class Health
          {
            hitpoints=1000;
            transferToGlobalCoef=1;
          };
        };
        class FuelTank
        {
          class Health
          {
            hitpoints=600;
            transferToGlobalCoef=0;
          };
        };
      };
    };
  };

  // ###################################################################################################################
  // Sedan_02 - SARKA 4AT RWD
  // ###################################################################################################################
  class Sedan_02_Wheel: CarWheel
  {
    itemSize[]={6,6};
    weight=14000;
    repairableWithKits[]={6};
    repairCosts[]={30};
    //radiusByDamage[]={0, 0.33000001, 0.30000001, 0.28999999, 0.99980003, 0.25, 0.99989998, 0.20999999};
    radiusByDamage[]={0, 0.33, 0.3, 0.29, 0.9998, 0.25, 0.9999, 0.21};
    //radius=0.33000001;
    radius=0.33;
    //width=0.16;
    width=0.17;
    //tyreOffroadResistance=0.60000002;
    tyreOffroadResistance=1.2;
    //tyreGrip=0.81999999;
    tyreGrip=1.65;
    //tyreRollResistance=0.0099999998;
    tyreRollResistance=0.02;
  };
  class Sedan_02: CarScript
  {
    fuelCapacity=38;
    fuelConsumption=7;
    class SimulationModule
    {
      class Steering
      {
        maxSteeringAngle=30;
        increaseSpeed[]={0, 40, 30, 20, 60, 10, 100, 5};
        decreaseSpeed[]={0, 90, 60, 70, 100, 50};
        centeringSpeed[]={0, 0, 15, 35, 60, 65, 100, 90};
      };
      class Throttle
      {
        //reactionTime=0.80000001;
				reactionTime=0.4;
				defaultThrust=0.75;
				gentleThrust=0.5;
				turboCoef=3.8;
				gentleCoef=0.5;
      };
      class Brake
      {
        //pressureBySpeed[]={0, 0.85000002, 10, 0.75, 20, 0.44999999, 40, 0.34999999, 80, 0.40000001, 100, 0.44999999, 120, 0.64999998};
        pressureBySpeed[]={0, 0.85, 10, 0.75, 20, 0.45, 40, 0.35, 80, 0.4, 100, 0.45, 120, 0.65};
        //gentleCoef=0.69999999;
        gentleCoef=0.7;
        //minPressure=0.30000001;
        minPressure=0.3;
        //reactionTime=0.34999999;
        reactionTime=0.35;
        driverless=0.1;
      };
      class Aerodynamics
      {
        frontalArea=2;
        //dragCoefficient=0.34999999;
        dragCoefficient=0.35;
      };
      drive="DRIVE_RWD";
      class Engine
      {
        //torqueCurve[]={600, 0, 990, 50, 1800, 75, 3000, 82, 5000, 71, 7000, 0};
        torqueCurve[]={600, 0, 1200, 55.2, 2200, 82.8, 3400, 92.0, 4800, 78.2, 6200, 0};
        inertia=0.2;
        frictionTorque=80;
        rollingFriction=0.5;
        viscousFriction=0;
        rpmIdle=900;
        rpmMin=1000;
        rpmClutch=1500;
        //rpmRedline=5750;
        rpmRedline=5800;
      };
      class Clutch
      {
        maxTorqueTransfer=165;
        uncoupleTime=0.1;
        //coupleTime=0.30000001;
        coupleTime=0.3;
      };
      class Gearbox
      {
        // type="GEARBOX_MANUAL";
        type="GEARBOX_AUTOMATIC";
        reverse=3.27;
        //ratios[]={3.8,2.1199999,1.41,0.95999998};
        ratios[]={3.370,2.210,1.449,0.950};
      };
      class Axles
      {
        class Front
        {
          maxBrakeTorque=1220;
          wheelHubMass=5;
          wheelHubRadius=0.17;
          class Suspension
          {
            stiffness=25000;
            //compression=1600;
            compression=2800;
            //damping=5200;
            damping=11700;
            travelMaxUp=0.07;
            travelMaxDown=0.079999998;
          };
        };
        class Rear
        {
          maxBrakeTorque=1040;
          maxHandbrakeTorque=2400;
          wheelHubMass=5;
          wheelHubRadius=0.17;
          class Differential
          {
            ratio=4.2199998;
            type="DIFFERENTIAL_OPEN";
          };
          class Suspension
          {
            stiffness=21500;
            //compression=1800;
            compression=3150;
            //damping=5600;
            damping=12600;
            travelMaxUp=0.1;
            travelMaxDown=0.1;
          };
        };
      };
    };
    class Cargo
    {
      //itemsCargoSize[]={10, 30};
      itemsCargoSize[]={10, 40};
      allowOwnedCargoManipulation=1;
      openable=0;
    };
    class DamageSystem
    {
      class GlobalHealth
      {
        class Health
        {
          hitpoints=1000;
        };
      };
      class DamageZones
      {
        class Chassis
        {
          class Health
          {
            hitpoints=3000;
            transferToGlobalCoef=0;
          };
        };
        class Front
        {
          class Health
          {
            hitpoints=1000;
            transferToGlobalCoef=0;
          };
        };
        class Reflector_1_1
        {
          class Health
          {
            hitpoints=10;
            transferToGlobalCoef=0;
          };
        };
        class Back
        {
          class Health
          {
            hitpoints=1000;
            transferToGlobalCoef=0;
          };
        };
        class Roof
        {
          class Health
          {
            hitpoints=600;
            transferToGlobalCoef=0;
          };
        };
        class Fender_1_1
        {
          class Health
          {
            hitpoints=800;
            transferToGlobalCoef=0;
          };
        };
        class WindowFront
        {
          class Health
          {
            hitpoints=90;
            transferToGlobalCoef=0;
          };
        };
        class Engine
        {
          fatalInjuryCoef=0.001;
          class Health
          {
            hitpoints=1000;
            transferToGlobalCoef=1;
          };
        };
        class FuelTank
        {
          class Health
          {
            hitpoints=400;
            transferToGlobalCoef=0;
          };
        };
      };
    };
  };

  // ###################################################################################################################
  // CivilianSedan - OLGA 5AT RWD
  // ###################################################################################################################
  class CivSedanWheel: CarWheel
  {
    itemSize[]={6,6};
    weight=12000;
    repairableWithKits[]={6};
    repairCosts[]={25};
    //radiusByDamage[]={0.0, 0.34, 0.30000001, 0.30000001, 0.99980003, 0.25, 0.99989998, 0.2};
    radiusByDamage[]={0.0, 0.34, 0.3, 0.3, 0.9998, 0.25, 0.9999, 0.2};
    radius=0.34;
    //width=0.14;
    width=0.15;
    //tyreOffroadResistance=0.80000001;
    tyreOffroadResistance=1.0;
    //tyreGrip=0.85000002;
    tyreGrip=1.9;
    //tyreRollResistance=0.0080000004;
    tyreRollResistance=0.016;
  };
  class CivilianSedan: CarScript
  {
    fuelCapacity=55;
    fuelConsumption=13;
    class SimulationModule
    {
      class Steering
      {
        maxSteeringAngle=35;
        increaseSpeed[]={0, 50, 10, 40, 30, 30, 60, 15, 100, 7, 120, 4};
        decreaseSpeed[]={0, 90, 60, 60, 120, 40};
        centeringSpeed[]={0, 0, 15, 30, 60, 60, 100, 80};
      };
      class Throttle
      {
        //reactionTime=0.34999999;
        reactionTime=0.25;
        //defaultThrust=0.64999998;
        defaultThrust=0.65;
        //gentleThrust=0.55000001;
        gentleThrust=0.55;
        //turboCoef=6;
        turboCoef=3;
        //gentleCoef=0.69999999;
        gentleCoef=0.7;
      };
      class Brake
      {
        //pressureBySpeed[]={0, 0.43000001, 10, 0.38, 20, 0.34999999, 40, 0.25, 50, 0.27000001, 80, 0.28999999, 100, 0.31, 140, 0.38};
        pressureBySpeed[]={0, 0.43, 10, 0.38, 20, 0.35, 40, 0.25, 50, 0.27, 80, 0.29, 100, 0.31, 140, 0.38};
        //gentleCoef=0.60000002;
        gentleCoef=0.6;
        minPressure=0.2;
        reactionTime=0.25;
        driverless=0.1;
      };
      class Aerodynamics
      {
        frontalArea=2.2;
        //dragCoefficient=0.44999999;
        dragCoefficient=0.45;
        //downforceCoefficient=0.80000001;
        downforceCoefficient=0.8;
        //downforceOffset[]={0, 0.40000001, -2.2};
        downforceOffset[]={0, 0.4, -2.2};
      };
      drive="DRIVE_RWD";
      class Engine
      {
        //torqueCurve[]={400, 0, 1000, 157, 1700, 183, 2500, 187, 4500, 147, 6000, 0};
        torqueCurve[]={400, 0, 950, 150, 2000, 190, 3500, 205, 5000, 165, 7400, 0};
        //inertia=0.44999999;
        inertia=0.45;
        frictionTorque=130;
        rollingFriction=1.5;
        viscousFriction=0.5;
        rpmIdle=900;
        rpmMin=1000;
        //rpmClutch=1250;
        rpmClutch=1500;
        //rpmRedline=4700;
        rpmRedline=6200;
      };
      class Clutch
      {
        maxTorqueTransfer=400;
        uncoupleTime=0.30000001;
        coupleTime=0.30000001;
      };
      class Gearbox
      {
        // type="GEARBOX_MANUAL";
        type="GEARBOX_AUTOMATIC";
        reverse=3.51;
        //ratios[]={3.5,2.26,1.45,1};
        ratios[]={3.500,2.559,1.871,1.368,1.000};
      };
      class Axles
      {
        class Front
        {
          maxBrakeTorque=2100;
          wheelHubMass=10;
          wheelHubRadius=0.15000001;
          class Suspension
          {
            stiffness=60000;
            //compression=2100;
            compression=3675;
            //damping=5500;
            damping=12375;
            travelMaxUp=0.079000004;
            travelMaxDown=0.059999999;
          };
        };
        class Rear
        {
          maxBrakeTorque=2200;
          maxHandbrakeTorque=4400;
          wheelHubMass=10;
          wheelHubRadius=0.15000001;
          class Differential
          {
            ratio=4.0999999;
            type="DIFFERENTIAL_OPEN";
          };
          class Suspension
          {
            stiffness=34000;
            //compression=2000;
            compression=3500;
            //damping=5100;
            damping=11475;
            travelMaxUp=0.086000003;
            travelMaxDown=0.133;
          };
        };
      };
    };
    class Cargo
    {
      //itemsCargoSize[]={10, 40};
      itemsCargoSize[]={10, 50};
      allowOwnedCargoManipulation=1;
      openable=0;
    };
    class DamageSystem
    {
      class GlobalHealth
      {
        class Health
        {
          hitpoints=1000;
        };
      };
      class DamageZones
      {
        class Chassis
        {
          class Health
          {
            hitpoints=3000;
            transferToGlobalCoef=0;
          };
        };
        class Front
        {
          class Health
          {
            hitpoints=1500;
            transferToGlobalCoef=0;
          };
        };
        class Reflector_1_1
        {
          class Health
          {
            hitpoints=20;
            transferToGlobalCoef=0;
          };
        };
        class Back
        {
          class Health
          {
            hitpoints=1500;
            transferToGlobalCoef=0;
          };
        };
        class Roof
        {
          class Health
          {
            hitpoints=700;
            transferToGlobalCoef=0;
          };
        };
        class Fender_1_1
        {
          class Health
          {
            hitpoints=1200;
            transferToGlobalCoef=0;
          };
        };
        class WindowFront
        {
          class Health
          {
            hitpoints=120;
            transferToGlobalCoef=0;
          };
        };
        class Engine
        {
          fatalInjuryCoef=0.001;
          class Health
          {
            hitpoints=1000;
            transferToGlobalCoef=1;
          };
        };
        class FuelTank
        {
          class Health
          {
            hitpoints=600;
            transferToGlobalCoef=0;
          };
        };
      };
    };
  };

  // ###################################################################################################################
  // Offroad_02 - M1025 6AT AWD
  // ###################################################################################################################
  class Offroad_02_Wheel: CarWheel
  {
    //itemSize[]={10,10};
    itemSize[]={9,9};
    //weight=65000;
    weight=35000;
    repairableWithKits[]={6};
    repairCosts[]={66};
    //radiusByDamage[]={0, 0.5, 0.30000001, 0.40000001, 0.99980003, 0.30000001, 0.99989998, 0.2};
    radiusByDamage[]={0, 0.5, 0.3, 0.4, 0.9998, 0.3, 0.9999, 0.2};
    radius=0.44;
    //width=0.23;
    width=0.26;
    //tyreOffroadResistance=1;
    tyreOffroadResistance=2.5;
    //tyreGrip=0.94999999;
    tyreGrip=2.375;
    //tyreRollResistance=0.017999999;
    tyreRollResistance=0.045;
  };
  class Offroad_02: CarScript
  {
    //fuelCapacity=115;
    fuelCapacity=155;
    fuelConsumption=30;
    batterySlot="TruckBattery";
    class SimulationModule
    {
      class Steering
      {
        //maxSteeringAngle=30;
        maxSteeringAngle=35;
        increaseSpeed[]={0, 40, 30, 20, 100, 10};
        decreaseSpeed[]={0, 80, 60, 40, 90, 20};
        centeringSpeed[]={0, 0, 15, 25, 60, 40, 100, 60};
      };
      class Throttle
      {
        //reactionTime=1;
        reactionTime=0.55;
        //defaultThrust=0.85000002;
        defaultThrust=0.85;
        //gentleThrust=0.69999999;
        gentleThrust=0.7;
        //turboCoef=4;
        turboCoef=6;
        gentleCoef=0.75;
      };
      class Brake
      {
        //pressureBySpeed[]={0,0.85000002,10,0.75,20,0.64999998,50,0.44999999,80,0.60000002,100,0.75};
        pressureBySpeed[]={0, 0.85, 10, 0.75, 20, 0.65, 50, 0.45, 80, 0.6, 100, 0.75};
        //gentleCoef=0.69999999;
        gentleCoef=0.7;
        minPressure=0.2;
        //reactionTime=0.15000001;
        reactionTime=0.15;
        driverless=0.1;
      };
      class Aerodynamics
      {
        frontalArea=3.05;
        dragCoefficient=0.58;
      };
      drive="DRIVE_AWD";
      class Engine
      {
        //torqueCurve[]={525, 0, 1000, 200, 1300, 313, 2500, 384, 3600, 316, 5120, 0};
        torqueCurve[]={500, 0, 900, 340, 1400, 420, 2600, 480, 3900, 440, 5400, 0};
        inertia=0.2;
        frictionTorque=90;
        rollingFriction=0.7;
        viscousFriction=1;
        rpmIdle=625;
        rpmMin=800;
        //rpmClutch=1600;
        rpmClutch=1400;
        //rpmRedline=3700;
        rpmRedline=4500;
      };
      class Clutch
      {
        //maxTorqueTransfer=650;
        maxTorqueTransfer=1300;
        uncoupleTime=0.2;
        coupleTime=0.1;
      };
      class Gearbox
      {
        //type="GEARBOX_AUTOMATIC";
        type="GEARBOX_MANUAL";
        //reverse=2.0799999;
        reverse=3.08;
        //ratios[]={2.48, 1.48, 1, 0.75};
        ratios[]={4.07, 2.84, 1.98, 1.18, 0.87};
      };
      class CentralDifferential
      {
        //ratio=2.1210001;
        ratio=2.121;
        type="DIFFERENTIAL_LOCKED";
      };
      class Axles
      {
        class Front
        {
          maxBrakeTorque=4700;
          maxHandbrakeTorque=10000;
          wheelHubMass=20;
          wheelHubRadius=0.15000001;
          class Differential
          {
            ratio=2.73;
            type="DIFFERENTIAL_LOCKED";
          };
          class Suspension
          {
            stiffness=50000;
            //compression=3300;
            compression=5775;
            //damping=4100;
            damping=9225;
            travelMaxUp=0.25;
            travelMaxDown=0.25;
          };
        };
        class Rear
        {
          maxBrakeTorque=4000;
          maxHandbrakeTorque=10000;
          wheelHubMass=20;
          wheelHubRadius=0.15000001;
          class Differential
          {
            ratio=2.73;
            type="DIFFERENTIAL_LOCKED";
          };
          class Suspension
          {
            stiffness=37500;
            //compression=3000;
            compression=3000;
            //damping=3600;
            damping=3600;
            travelMaxUp=0.25;
            travelMaxDown=0.25;
          };
        };
      };
    };
    class Cargo
    {
      //itemsCargoSize[]={10, 30};
      itemsCargoSize[]={10, 60};
      allowOwnedCargoManipulation=1;
      openable=0;
    };
    class DamageSystem
    {
      class GlobalHealth
      {
        class Health
        {
          hitpoints=1000;
        };
      };
      class DamageZones
      {
        class Chassis
        {
          class Health
          {
            hitpoints=3000;
            transferToGlobalCoef=0;
          };
        };
        class Front
        {
          class Health
          {
            hitpoints=1000;
            transferToGlobalCoef=0;
          };
        };
        class Reflector_1_1
        {
          class Health
          {
            hitpoints=10;
            transferToGlobalCoef=0;
          };
        };
        class Reflector_2_1;
        class Back
        {
          class Health
          {
            hitpoints=1000;
            transferToGlobalCoef=0;
          };
        };
        class Roof
        {
          class Health
          {
            hitpoints=600;
            transferToGlobalCoef=0;
          };
        };
        class Fender_1_1
        {
          class Health
          {
            hitpoints=800;
            transferToGlobalCoef=0;
          };
        };
        class WindowLeft
        {
          class Health
          {
            hitpoints=160;
            transferToGlobalCoef=0;
          };
        };
        class WindowRight;
        class Engine
        {
          fatalInjuryCoef=0.001;
          class Health
          {
            hitpoints=1000;
            transferToGlobalCoef=1;
          };
          inventorySlots[]={"TruckBattery", "GlowPlug"};
          inventorySlotsCoefs[]={0.1, 0.0099999998};
        };
        class FuelTank
        {
          class Health
          {
            hitpoints=400;
            transferToGlobalCoef=0;
          };
        };
      };
    };
  };

  // ###################################################################################################################
  // Truck_01 - M3S 8MT 6X4
  // ###################################################################################################################
  class Truck_01_Wheel: CarWheel
  {
    //itemSize[]={10,10};
    itemSize[]={9,9};
    //weight=30000;
    weight=25000;
    repairableWithKits[]={6};
    repairCosts[]={50};
    //radiusByDamage[]={0, 0.465, 0.30000001, 0.38, 0.99980003, 0.34999999, 0.99989998, 0.28};
    radiusByDamage[]={0, 0.465, 0.3, 0.38, 0.9998, 0.35, 0.9999, 0.28};
    radius=0.465;
    //width=0.2;
    width=0.24;
    //tyreOffroadResistance=0.98000002;
    tyreOffroadResistance=2.0;
    //tyreGrip=0.94999999;
    tyreGrip=2.0;
    //tyreRollResistance=0.015;
    tyreRollResistance=0.03;
  };
  class Truck_01_WheelDouble: Truck_01_Wheel
  {
    //weight=50000;
    weight=45000;
    repairableWithKits[]={6};
    repairCosts[]={75};
    //width=0.40000001;
    width=0.48;
    //tyreOffroadResistance=1;
    tyreOffroadResistance=2.5;
    //tyreGrip=1;
    tyreGrip=2.25;
    //tyreRollResistance=0.017999999;
    tyreRollResistance=0.045;
  };
  class Truck_01_Base: CarScript
  {
    //fuelCapacity=120;
    fuelCapacity=165;
    //fuelConsumption=30;
    fuelConsumption=40;
    batterySlot="TruckBattery";
    class SimulationModule
    {
      class Steering
      {
        maxSteeringAngle=35;
        increaseSpeed[]={0, 25, 50, 15};
        decreaseSpeed[]={0, 50, 50, 40};
        centeringSpeed[]={0, 25, 50, 15};
      };
      class Throttle
      {
        reactionTime=0.2;
        //defaultThrust=0.80000001;
        defaultThrust=0.8;
        //gentleThrust=0.60000002;
        gentleThrust=0.6;
        //turboCoef=1.15;
        turboCoef=2.5;
        gentleCoef=0.5;
      };
      class Brake
      {
        //pressureBySpeed[]={0, 0.5, 10, 0.46000001, 30, 0.43000001, 40, 0.34999999, 60, 0.40000001, 80, 0.5};
        pressureBySpeed[]={0, 0.5, 10, 0.46, 30, 0.43, 40, 0.34, 60, 0.4, 80, 0.5};
        //gentleCoef=0.60000002;
        gentleCoef=0.6;
        minPressure=0.2;
        //reactionTime=0.30000001;
        reactionTime=0.3;
        driverless=0.1;
      };
      class Aerodynamics
      {
        frontalArea=5.75;
        //dragCoefficient=0.52999997;
        dragCoefficient=0.53;
      };
      drive="DRIVE_642";
      class Engine
      {
        //torqueCurve[]={525, 0, 1000, 330, 1400, 340, 1900, 300, 2500, 100, 3000, 0};
        torqueCurve[]={500, 0, 950, 540, 1350, 580, 1850, 580, 2600, 140, 3000, 0};
        //inertia=3.25;
        inertia=2.75;
        frictionTorque=100;
        rollingFriction=3;
        viscousFriction=2.5;
        rpmIdle=650;
        rpmMin=750;
        rpmClutch=850;
        //rpmRedline=2400;
        rpmRedline=2600;
      };
      class Clutch
      {
        //maxTorqueTransfer=720;
        maxTorqueTransfer=1440;
        uncoupleTime=0.2;
        //coupleTime=0.64999998;
        coupleTime=0.65;
      };
      class Gearbox
      {
        type="GEARBOX_MANUAL";
        //reverse=6.2800002;
        reverse=5.725;
        //ratios[]={6.1900001, 3.1300001, 1.75, 1};
        ratios[]={7.018, 4.002, 2.715, 2.069, 1.453, 1.056};
      };
      class CentralDifferential
      {
        ratio=0.75;
        type="DIFFERENTIAL_LOCKED";
      };
      class Axles
      {
        class Front
        {
          maxBrakeTorque=9000;
          wheelHubMass=25;
          wheelHubRadius=0.30000001;
          class Suspension
          {
            stiffness=65000;
            //compression=3000;
            compression=5250;
            //damping=7000;
            damping=15750;
            travelMaxUp=0.14;
            travelMaxDown=0.15000001;
          };
        };
        class Middle
        {
          maxBrakeTorque=6200;
          maxHandbrakeTorque=12000;
          wheelHubMass=45;
          wheelHubRadius=0.30000001;
          class Differential
          {
            ratio=8.3500004;
            type="DIFFERENTIAL_LOCKED";
          };
          class Suspension
          {
            stiffness=55000;
            //compression=2500;
            compression=4375;
            //damping=8000;
            damping=18000;
            travelMaxUp=0.094999999;
            travelMaxDown=0.125;
          };
        };
        class Rear
        {
          maxBrakeTorque=6200;
          maxHandbrakeTorque=12000;
          wheelHubMass=45;
          wheelHubRadius=0.30000001;
          class Differential
          {
            ratio=8.3500004;
            type="DIFFERENTIAL_LOCKED";
          };
          class Suspension
          {
            stiffness=55000;
            //compression=2500;
            compression=4375;
            //damping=8000;
            damping=18000;
            travelMaxUp=0.094999999;
            travelMaxDown=0.125;
          };
        };
      };
    };
    class Cargo
    {
      //itemsCargoSize[]={10, 40};
      itemsCargoSize[]={10, 60};
      allowOwnedCargoManipulation=1;
      openable=0;
    };
    class DamageSystem
    {
      class GlobalHealth
      {
        class Health
        {
          hitpoints=1500;
        };
      };
      class DamageZones
      {
        class Chassis
        {
          class Health
          {
            hitpoints=3000;
            transferToGlobalCoef=0;
          };
        };
        class Engine
        {
          fatalInjuryCoef=0.001;
          class Health
          {
            hitpoints=1500;
            transferToGlobalCoef=1;
          };
          inventorySlots[]={"TruckBattery", "GlowPlug"};
          inventorySlotsCoefs[]={0.1, 0.050000001};
        };
        class Front
        {
          class Health
          {
            hitpoints=2500;
            transferToGlobalCoef=0;
          };
        };
        class BackWood
        {
          class Health
          {
            hitpoints=3000;
            transferToGlobalCoef=0;
          };
        };
        class BackTarp
        {
          class Health
          {
            hitpoints=1000;
            transferToGlobalCoef=0;
          };
        };
        class Roof
        {
          class Health
          {
            hitpoints=500;
            transferToGlobalCoef=0;
          };
        };
        class Fender_1_1
        {
          class Health
          {
            hitpoints=800;
            transferToGlobalCoef=0;
          };
        };
        class WindowLeft
        {
          class Health
          {
            hitpoints=150;
            transferToGlobalCoef=0;
          };
        };
        class FuelTank
        {
          class Health
          {
            hitpoints=300;
            transferToGlobalCoef=0;
          };
        };
        class Reflector_1_1
        {
          class Health
          {
            hitpoints=50;
            transferToGlobalCoef=0;
          };
        };
      };
    };
  };
  class Truck_01_Covered: Truck_01_Base
  {
    class Cargo
    {
      //itemsCargoSize[]={10, 60};
      itemsCargoSize[]={10, 100};
      allowOwnedCargoManipulation=1;
      openable=0;
    };
  };
  class Truck_01_Chassis;
  class Truck_01_Cargo: Truck_01_Chassis
  {
    class Cargo
		{
			//itemsCargoSize[]={10, 60};
			itemsCargoSize[]={10, 100};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
  }
};
