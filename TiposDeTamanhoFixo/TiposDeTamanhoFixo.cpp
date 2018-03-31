
	void EntenderTiposDeTamanhoFixo(){
	std::wcout << "-BEGIN-" << std::endl;

	uint8_t ui8=UINT8_MAX;
	std::wcout << ui8 <<","<< sizeof(ui8)<< std::endl;

	uint16_t ui16=UINT16_MAX;
	std::wcout << ui16 <<"," << sizeof(ui16)<< std::endl;

	uint32_t ui32= UINT32_MAX;
	std::wcout << ui32 <<","<<sizeof(ui32)<< std::endl;

	uint64_t ui64 = UINT64_MAX;
	std::wcout << ui64 <<","<<sizeof(ui64)<< std::endl;

	std::wcout << L"-END-" << std::endl;
	}
