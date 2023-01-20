#pragma once
#include "DataTypes.h"
#include "Effect.h"

class MeshRepresentation
{
public:
	MeshRepresentation(ID3D11Device* pDevice, std::vector<Vertex>& vertices, std::vector<int>& indices);
	~MeshRepresentation() = default;

	void Render(ID3D11DeviceContext* pDeviceContext);

private:
	ID3D11Buffer* m_pVertexBuffer;
	ID3D11Buffer* m_pIndexBuffer;
	ID3D11InputLayout* m_pInputLayout;
	uint32_t m_NumIndices;
	Effect* m_pEffect;
	ID3DX11EffectTechnique* m_pTechnique;
};

