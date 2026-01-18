class CfgPatches
{
  class VanillaVehicles
  {
    units[]={};
    weapons[]={};
    requiredVersion=0.1;
    requiredAddons[]={ "DZ_Data", "DZ_Scripts" };
  };
};

class CfgMods
{
  class VanillaVehicles
  {
    dir="VanillaVehicles";
    hideName=0;
    hidePicture=0;
    extra=0;
    name="VanillaVehicles";
    picture="VanillaVehicles\data\picture.paa";
    logoSmall="VanillaVehicles\data\logoSmall.paa";
    logo="VanillaVehicles\data\logo.paa";
    logoOver="VanillaVehicles\data\logo.paa";
    action="https://steamcommunity.com/sharedfiles/filedetails/?id=3540323850";
    credits="moldypenguins";
    author="moldypenguins";
    authorID="76561198312711389";
    version="1.4";
    type="mod";
    dependencies[]={ "World" };
    class defs
    {
      class engineScriptModule
      {
        value="";
        files[]={ "VanillaVehicles\scripts\1_core" };
      };
      class worldScriptModule
      {
        value="";
        files[]={"VanillaVehicles\scripts\4_world"};
      };
    }
  };
};
