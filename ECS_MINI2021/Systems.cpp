#include "Systems.h"
#include "World.h"

Render::Render()
{
	System::SetMask<Position, Texture>();
}

void Render::ApplyLogic(World* worldContext)
{
	SDL_RenderClear(worldContext->renderer);
	for (int i = 0; i < MAX_ENTITIES; i++)
	{
		if (worldContext->GetEntities()[i].HasComponents(componentMask))
		{
			Texture* textureComponent = worldContext->GetComponent<Texture>(i);
			Position* posComponent = worldContext->GetComponent<Position>(i);

			SDL_Rect finalRect = { (int)posComponent->x,
									(int)posComponent->y,
									textureComponent->textureRect.w,
									textureComponent->textureRect.h };

			SDL_RenderCopy(worldContext->renderer, textureComponent->texture, &textureComponent->textureRect, &finalRect);
		}
	}
	SDL_RenderPresent(worldContext->renderer);
}
