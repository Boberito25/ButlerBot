function [path] = astar(start, startconfig, target,costf, heuristic, jacobian, constraint, h)
	x = -30:h:30
	y = -30:h:30
	z = 0:h:30

	xs = length(xs);
	ys = length(ys);
	zs = length(zs);

	WS = cell(xs,ys,zs,2);
	[starts, Is] = find8closest(start, x, y, z);
	Frontier = Is;
	[targets, It] = find8closest(start, x, y, z);
	targets = find8closest(target, x, y, z); 


	% starts %
	for i = 1:length(Frontier)
		WS(Is(1,i),Is(2,i), Is(3,i),2) = costf(startconfig, start, translateCell(I(:,i),h))
		WS(Is(1,i),Is(2,i), Is(3,i),1) = -1*ones(3,1);
	end	

	% loop %
	currentstate = start
	while(~targetreached(currentstate,It))
		pstate = priority(Frontier, constf, heuristic)
		NewFrontier = expandfrontier(WS, pstate);
		Frontier = [Frontier, NewFrontier];
		Frontier = find(Frontier ~= pstate);
		
	end
end

function [hasreached] = targetreached(state, Its)
end

%Expand the frontier at a given state
function [Idxs] expandfrontier(WS, state)
end

% Returns the index of the cell required
function [I] = priority(frontier, costf, heuristic) 
end

%Translates cell positions in to positions 
%in real coordinates

function [p] translateCell(I,h)

end




%Finds grid points
function [states, I] = find8closest(spec,x,y,z)
	nx = length(x);
	ny = length(y);
	nz = length(z);
	%TODO%

end