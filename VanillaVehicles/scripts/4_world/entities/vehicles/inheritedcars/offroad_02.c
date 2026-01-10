modded class Offroad_02
{
	override bool CanReleaseAttachment( EntityAI attachment )
	{
		if (!super.CanReleaseAttachment(attachment))
		{
			return false;
		}
		string attType = attachment.GetType();
		switch (attType)
		{
      case "TruckBattery":
      case "GlowPlug":
        if (GetCarDoorsState("Offroad_02_Hood") == CarDoorState.DOORS_CLOSED || EngineIsOn())
        {
          return false;
        }
        break;
    }
		return true;
	}

  override bool IsVitalTruckBattery()
	{
		return true;
	}

	override bool IsVitalGlowPlug()
	{
		return true;
	}

	override bool IsVitalCarBattery()
	{
		return false;
	}

	override bool IsVitalSparkPlug()
	{
		return false;
	}

	override bool IsVitalEngineBelt()
	{
		return false;
	}

	override bool IsVitalRadiator()
	{
		return false;
	}

};
