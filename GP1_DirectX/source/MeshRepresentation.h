#pragma once
#include "DataTypes.h"
#include "Effect.h"

using namespace dae;

class MeshRepresentation
{
public:
	MeshRepresentation(ID3D11Device* pDevice, std::vector<Vertex>& vertices, std::vector<int>& indices);
	~MeshRepresentation();

	MeshRepresentation(const MeshRepresentation&)					= delete;
	MeshRepresentation(MeshRepresentation&&) noexcept				= delete;
	MeshRepresentation& operator=(const MeshRepresentation&)		= delete;
	MeshRepresentation& operator=(MeshRepresentation&&) noexcept	= delete;

	void Render(ID3D11DeviceContext* pDeviceContext);
private:
	ID3DX11EffectTechnique* m_pTechnique{};
	ID3D11InputLayout* m_pInputLayout{};
	ID3D11Buffer* m_pVertexBuffer{};
	ID3D11Buffer* m_pIndexBuffer{};
	uint32_t m_NumIndices{};
	Effect* m_pEffect{};
};
