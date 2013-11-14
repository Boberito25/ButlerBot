function [WS, path] = astar(start, startconfig, target,costf, heuristic, jacobian, constraint, h, tstep)
	x = -30:h:30
	y = -30:h:30
	z = 0:h:30

	xs = length(xs);
	ys = length(ys);
	zs = length(zs);

	WS = cell(xs,ys,zs,3);
	[starts, Is] = find8closest(start, x, y, z);
	Frontier = Is;
	[targets, It] = find8closest(start, x, y, z);
	targets = find8closest(target, x, y, z); 


	% starts %
	[~, n] = size(Frontier);
	for i = 1:n
		next = translateCell(I(:,i),h);
		newconfig = NewConfig(start,next,Jacobian,tstep) 
		WS(Is(1,i),Is(2,i),Is(3,i),1)  = newconfig; %Configuration 
		WS(Is(1,i),Is(2,i),Is(3,i),2)  = costf(next,start,newconfig, startconfig);
		WS(Is(1,i),Is(2,i),Is(3,i),3)  = [-1;-1;-1]; %Previous
	end	
	currentstate = priority(Frontier, cost, heuristic, WS)
	% loop %
	while(~targetreached(currentstate,It))
		Idxs = expandfrontier(Frontier,WS, currentstate);
		Frontier = [Frontier, Idxs];
		% Expand frontier around prioritys
		[~,n] = size(idxs);
		for i = 1:n
				current = translateCell(currentstate,h);
				next = translateCell(Idxs(:,i),h);
				newconfig = NewConfig(currents,next,Jacobian,tstep)
				currentconfig = WS(currentstate(1),currentstate(2), currentstate(3), 1);
				WS(Idxs(1,i), Idxs(2,i), Idxs(3,i), 1) = newconfig;
				WS(Idxs(1,i), Idxs(2,i), Idxs(3,i), 2) = costf(next,current,newconfig, currentconfig);
				WS(Idxs(1,i), Idxs(2,i), Idxs(3,i), 3) = currentstate; 
			
		end
		%Filter current state from frontier
		ridx = -1;
		[~,n] = size(Frontier);
		for i = 1:n
			if(Frontier(:,i) == currentstate)
				ridx = i;
			end
		end
		if(ridx ~= n)
			Frontier = [Frontier(:,1:ridx-1) Frontier(:,ridx+1 : n)];
		else
			Frontier = Frontier(:, 1:ridx-1);
		end

		%Update priority
		currentstate = priority()
	end

	%back trace path
	path = tracePath(WS, It);
end

function [newconfig] = NewConfig(curremt, next, Jacobian, timestep)
end

function [path] = tracepath(WS, It)
end

function [hasreached] = targetreached(state, Its)
end

%Expand the frontier at a given state
function [NewFrontier] expandfrontier(Frontier,WS, state)
end

% Returns the index of the cell required
function [I] = priority(frontier, costf, heuristic, WS) 
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